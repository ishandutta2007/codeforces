#include <bits/stdc++.h>

const int	MAX = 51;

char	map[MAX][MAX];
int		n, m, x;


int		sq(int n) {return n * n;}

int		distance(int posA, int posB)
{
	return sq(posA / m - posB / m) + sq(posA % m - posB % m);
}

int		compute(char c)
{
	if (c >= 'a' and c <= 'z')
	{
		for (int i(0); i < n; ++i)
			for (int j(0); j < m; ++j)
				if (map[i][j] == c)
					return 0;
		return -1;
	}
	else if (c >= 'A' and c <= 'Z')
	{
		c = tolower(c);
		int		min = 1e9;
		for (int i(0); i < n; ++i)
			for (int j(0); j < m; ++j)
			{
				if (map[i][j] == c)
				{
					int	min_dist = 1e9;
					for (int k(0); k < n; ++k)
						for (int l(0); l < m; ++l)
							if (map[k][l] == 'S')
								min_dist = std::min(min_dist, distance(i * m + j, k * m + l));
					min = std::min(min, min_dist);
				}
			}
		if (min == 1e9)
			return -1;
		if (min > x)
			return 1;
	}
	return 0;
}

int		main(void)
{
	std::cin >> n >> m >> x;
	x = sq(x);

	for (int i(0); i < n; ++i)
		std::cin >> map[i];

	int		N;
	std::cin >> N;

	int		answer(0);
	int		answers_min[26];
	int		answers_cap[26];

	for (int i(0); i < 26; ++i)
		answers_min[i] = compute(i + 'a'), answers_cap[i] = compute(i + 'A');

	while (N--)
	{
		char c;
		std::cin >> c;
		int		rep = (c >= 'A' and c <= 'Z') ? answers_cap[c - 'A'] : answers_min[c - 'a'];
		if (rep == -1)
		{
			std::cout << "-1\n";
			return 0;
		}
		answer += rep;
	}
	std::cout << answer << std::endl;
}