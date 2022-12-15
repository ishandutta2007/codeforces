#include <bits/stdc++.h>

const int	MAX = 101;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

int		N, M;

char map[MAX][MAX];

void	clear(char color)
{
	for (int i(0); i < N; ++i)
		for (int j(0); j < M; ++j)
			if (map[i][j] == color)
				map[i][j] = '.';
}

bool	is_safe(int y, int x)
{
	return y >= 0 and x >= 0 and y < N and x < M;
}

int		main(void)
{
	char	c;
	std::cin >> N >> M >> c;

	for (int i(0); i < N; ++i)
		std::cin >> map[i];

	int		cnt(0);
	for (int y(0); y < N; ++y)
	{
		for (int x(0); x < M; ++x)
		{
			if (map[y][x] == c)
			{
				for (int d(0); d < 4; ++d)
				{
					if (!is_safe(y + DY[d], x + DX[d]))
						continue ;
					if (map[y + DY[d]][x + DX[d]] != c and map[y + DY[d]][x + DX[d]] != '.')
						cnt++, clear(map[y+DY[d]][x+DX[d]]);
				}
			}
		}
	}
	
	std::cout << cnt << std::endl;
}