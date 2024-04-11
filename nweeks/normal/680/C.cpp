#include <bits/stdc++.h>

const int MAX = 101;


bool	prime(int n)
{
	for (int i(2); i < n; ++i)
		if (n % i == 0)
			return false;
	return true;
}

int		main(void)
{
	int		cnt(0);

	int		cur(2);
	
	for (int i(0); i < 20 and cnt < 2; ++i)
	{
		while (!prime(cur))
			++cur;

		std::cout << cur << std::endl;
		std::fflush(stdout);
		std::string s;
		std::cin >> s;

		if (s == "yes")
		{
			++cnt;
			if (cur < 10)
			{
				++i;
				std::cout << cur * cur << std::endl;
				std::fflush(stdout);
				std::cin >> s;
				if (s == "yes")
				{
					++cnt;
					break;
				}
			}
		}
		++cur;
	}
	if (cnt > 1)
		std::cout << "composite\n";
	else
		std::cout << "prime\n";
}