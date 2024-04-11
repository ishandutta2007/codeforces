#include <bits/stdc++.h>

int		main()
{
	std::string s;
	std::cin >> s;

	int	cur(0);
	for (int i(0); i < s.size(); ++i)
	{
		if (s[i] == '.')
		{
			std::cout << cur;
			cur = 0;
		}
		else if (cur == 1)
		{
			std::cout << cur + 1;
			cur = 0;
		}
		else
			++cur;
	}
	std::cout << std::endl;
}