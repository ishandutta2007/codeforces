#include <bits/stdc++.h>

int		main(void)
{
	int		parent[3] = {};

	for (int i(0); i < 3; ++i)
	{
		char a, b, comp;
		std::cin >> a >> comp >> b;
		if (comp == '>')
			parent[b - 'A']++;
		else
			parent[a - 'A']++;
	}

	for (int i(0); i < 3; ++i)
		for (int j(i + 1); j < 3; ++j)
			if (parent[i] == parent[j] or parent[i] > 2)
			{
				std::cout << "Impossible\n";
				return 0;
			}


	for (int i(0); i < 3; ++i)
		if (parent[i] == 2)
			std::cout << (char)(i + 'A');
	
	for (int i(0); i < 3; ++i)
		if (parent[i] == 1)
			std::cout << (char)(i + 'A');
	for (int i(0); i < 3; ++i)
		if (parent[i] == 0)
			std::cout << (char)(i + 'A');
	std::putchar('\n');
}