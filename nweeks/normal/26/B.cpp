#include <bits/stdc++.h>

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::string s;
	std::cin>>s;
	int	ans(0);
	int	count(0);

	for (auto c : s)
	{
		if (c == '(')
			count++;
		else
		{
			if (count > 0)
				count--;
			else
				ans++;
		}
	}
	std::cout << s.size() - ans -count<< std::endl;
}