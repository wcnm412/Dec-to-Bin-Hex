#include "main.h"
#include "random.h"

void binDivisionIterator(long long int number, std::array<bool, 64>& binary, const bool& negativeIndicator)
{
	if (negativeIndicator)
	{
		number *= -1;
	}
	for (int i {0}; i < 64; ++i)
	{
		if (number % 2 == 1)
		{
			binary[i] = 1;
		}
		if (number % 2 == 0)
		{
			binary[i] = 0;
		}
		number /= 2;
	}
}

void printBinArray(const std::array<bool, 64>& binary, const long long int& number)
{
	std::cout << "0b";
	for (int i {63}; i >= 0; --i)
	{
		if (number < 0)
		{
			std::cout << !binary[i];
		}
		else
		{
			std::cout << binary[i];
		}
	}
	std::cout << '\n';
}

void printHexArray(const std::array<bool, 64>& binary, const long long int& number, const bool& negativeIndicator)
{
	std::cout << "0x";
	std::array<char, 16> hex {}; 
	for (int i{0}; i <= 15; ++i)
	{
		//sum4 through for loop per 4-bit group
		std::bitset<4> block4bit {(negativeIndicator) ? static_cast<unsigned>(0b1111) : static_cast<unsigned>(0b0000)};
		for (int k {0}; k < 4; ++k)
		{
			if (binary[(4 * i) + k] == 1)
			{
				block4bit.flip(k);
			}
		}

		if ((block4bit.to_ulong() >= 0 ) && block4bit.to_ulong() <= 9)
		{
			hex[i] = '0' + static_cast<char>(block4bit.to_ulong());
		}
		else
		{
			switch(block4bit.to_ulong())
			{
				case 10:
				{
					hex[i] = 'A';
					break;
				}
				case 11:
				{
					hex[i] = 'B';
					break;
				}
				case 12:
				{
					hex[i] = 'C';
					break;
				}
				case 13:
				{
					hex[i] = 'D';
					break;
				}
				case 14:
				{
					hex[i] = 'E';
					break;
				}
				case 15:
				{
					hex[i] = 'F';
					break;
				}
				default:
				{
					std::cout << "\nerror at " << i;
					break;
				}
			}
		}
	}
	for (int i{0}; i <= 15; ++i)
	{
		std::cout << hex[15 - i];
	}
}


int main()
{
	long long int number {Random::get(INT64_MIN, INT64_MAX)};
	bool negativeIndicator {0};
	if (number < 0)
	{
		negativeIndicator = 1;
	}
	std::array<bool, 64> binary {};
	std::cout << number << '\n';

	binDivisionIterator(number, binary, negativeIndicator);
	printBinArray(binary, number);
	printHexArray(binary, number, negativeIndicator);

	return 0;
}