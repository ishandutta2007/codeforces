#include <bits/stdc++.h>

const int	MAX = 2001;

int	parent[MAX];
int	size[MAX];

int		dfs(int i)
{
	if (i == -1)
		return 0;
	if (size[i] != -1)
		return size[i];
	size[i] = 1 +dfs(parent[i]);
	return size[i];
}

int		main(void)
{
	for (int i(0); i < MAX; ++i)
		size[i] = -1;

	int	N;
	std::cin >> N;
	int		max(0);

	for (int i(1); i <= N; ++i)
		std::cin >> parent[i];

	for (int i(1); i <= N; ++i)
	{
		size[i] = dfs(i);
		max = std::max(max, size[i]);
	}
	std::cout << max << std::endl;
}