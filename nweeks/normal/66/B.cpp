#include <bits/stdc++.h>

const int	MAX = 1000;

int		heights[MAX];
int		N;

int		compute(int n)
{
	int		count(1);

	for (int i(n - 1); i >= 0 and heights[i] <= heights[i + 1]; --i, ++count);
	for (int i(n + 1); i < N and heights[i] <= heights[i - 1]; ++i, ++count);

	return count;
}

int		main(void)
{
	std::cin >> N;

	for (int i(0); i < N; ++i)
		std::cin >> heights[i];

	int		max(0);
	for (int i(0); i < N; ++i)
		max = std::max(max, compute(i));
	std::cout << max << std::endl;
}