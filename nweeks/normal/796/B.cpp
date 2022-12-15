#include <bits/stdc++.h>

int	main(void)
{
	std::ios_base::sync_with_stdio(false);
	int		n, m, k;
	std::cin >> n >> m >> k;
	std::vector<bool>	a(n);

	while (m--)
	{
		int	i;
		std::cin >> i;
		i--;
		a[i] = true;
	}

	int		cur = 0;
	if (a[cur])
	{
		std::cout << cur + 1 << std::endl;
		return 0;
	}

	while (k--)
	{
		int		i, j;
		std::cin >> i >> j;
		--i, --j;
		if (i == cur)
			cur = j;
		else if (j == cur)
			cur = i;
		if (a[cur])
		{
			std::cout << cur + 1 << std::endl;
			return 0;
		}
	}
	std::cout << cur + 1 << std::endl;
}