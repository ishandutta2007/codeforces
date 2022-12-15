#include <bits/stdc++.h>

int		main(void)
{
	std::string	colors = "ROYGBIV";

	int		N;
	std::cin >> N;

	for (int i(0); i < N / 7; ++i)
		std::cout << colors;
	for (int i(0); i < N % 7; ++i)
		std::cout << colors[3 + i % 4];
	std::cout << std::endl;
}