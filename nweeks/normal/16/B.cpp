#include <bits/stdc++.h>

struct Box
{
	long long count, matches;

	bool	operator<(Box other) const
	{
		return matches > other.matches;
	}
};

int		main(void)
{
	long long n, m;
	std::cin >> n >> m;

	std::vector<Box> boxes(m);

	for (auto& val : boxes)
		std::cin >> val.count >> val.matches;

	std::sort(boxes.begin(), boxes.end());

	long long answer(0);
	
	int		cur(0);
	while (n > 0 and cur < m)
	{
		answer += std::min(n, boxes[cur].count) * boxes[cur].matches;
		n -= std::min(n, boxes[cur].count);
		cur++;
	}
	std::cout << answer << std::endl;
}