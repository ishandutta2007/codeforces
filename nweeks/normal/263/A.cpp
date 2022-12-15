#include <bits/stdc++.h>

int		main()
{
	int		buf;
	int		answer;

	for (int i(0); i < 5; ++i)
		for (int j(0); j < 5; ++j)
		{
			std::cin >> buf;
			if (buf)
				answer = fabs(i - 2) + fabs(j - 2);
		}
	std::cout << answer << std::endl;
}