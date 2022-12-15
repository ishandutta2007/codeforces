#include <vector>
#include <iostream>

int		main(void)
{
	int		N, k;
	std::cin >> N >> k;

	std::vector<int>	h(N + 1);

	h[0] = 0;
	for (int i(1); i <= N; ++i)
	{
		std::cin >> h[i];
		h[i] += h[i - 1];
	}

	int	min(1e9), min_index(0);

	for (int i(k); i <= N; ++i)
		if (h[i] - h[i-k] < min)
			min = h[i] - h[i-k], min_index = i - k + 1;
	std::cout << min_index << std::endl;
}