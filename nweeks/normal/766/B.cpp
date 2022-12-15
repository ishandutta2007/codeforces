#include <iostream>
#include <vector>
#include <algorithm>

int		main(void)
{
	int	n;
	std::cin >> n;
	std::vector<int>	a(n);
	for (auto& val : a)
		std::cin >> val;
	std::sort(a.begin(), a.end());
	for (int  i(0); i <= n - 3; ++i)
		if (a[i] + a[i + 1] > a[i + 2])
		{
			std::cout << "YES\n";
			return 0;
		}
	std::cout << "NO\n";
	return 0;
}