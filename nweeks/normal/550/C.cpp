#include <bits/stdc++.h>

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::string s;
	std::cin >> s;

	for (auto c : s)
	{
		if ((c - '0') % 8 == 0)
		{
			std::cout << "YES\n"<<c<<"\n";
			return 0;
		}
	}
	for (int i(0); i < s.size(); ++i)
		for (int j(i+1); j < s.size(); ++j)
			if ((2 * (s[i] - '0') + s[j] - '0')%8==0)
			{
				std::cout <<"YES\n"<<s[i]<<s[j]<<std::endl;
				return 0;
			}
	for (int i(0); i < s.size(); ++i)
		for (int j(i + 1); j < s.size(); ++j)
			for (int k(j + 1); k < s.size(); ++k)
				if ((4 * (s[i] - '0') + 2 * (s[j] - '0') + s[k] - '0') % 8 == 0)
				{
					std::cout << "YES\n";
					std::cout << s[i] << s[j] << s[k] << std::endl;
					return 0;
				}
	std::cout << "NO\n";
	return 0;
}