#include <bits/stdc++.h>

int		main()
{
	int		N, x, y, z, summ_x(0), summ_y(0), summ_z(0);

	std::cin >> N;

	while (N--)
	{
		std::cin >> x >> y >> z;
		summ_x += x;
		summ_y += y;
		summ_z += z;
	}

	if (summ_x == 0 and summ_y == 0 and summ_z == 0)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NO" << std::endl;
	return (0);
}