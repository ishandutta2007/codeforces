#include <bits/stdc++.h>

int		main(void)
{
	std::string s;
	std::cin >> s;
	
	int	cnt(0);
	while (s.size() > 1)
	{
		cnt++;

		int		n(0);
		for (auto c : s)
			n += c - '0';
		s = std::to_string(n);
	}
	std::cout << cnt << std::endl;
}