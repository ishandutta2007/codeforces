#include <bits/stdc++.h>

std::string	answers[] = {"Waste", "Carrots", "Kiwis", "Grapes"};

int		main(void)
{
	int		n, m, k, t;
	std::cin >> n >> m >> k >> t;

	std::vector<long long>	waste(k);

	for (int i(0); i < k; ++i)
	{
		int		a, b;
		std::cin >> a >> b;
		--a, --b;
		waste[i] = a * m + b;
	}
	std::sort(waste.begin(), waste.end());

	while (t--)
	{
		long long a, b;
		std::cin >> a >> b;
		a--, b--;
		long long pos = a * m + b;

		int		cur(0);
		while (waste[cur] < pos and cur < k)
			++cur;
		if (cur < k and waste[cur] == pos)
			std::cout << answers[0] << std::endl;
		else
			std::cout << answers[(pos - cur) % 3 + 1] << std::endl;
	}

}