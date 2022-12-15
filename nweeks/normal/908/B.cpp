#include <bits/stdc++.h>

const int	MAX = 50;
const int	MAX_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

char		map[MAX][MAX];
int			dir[4];
	int	n,m;

bool		is_safe(int y, int x)
{
	return y >= 0 and x >= 0 and y < n and x < m and map[y][x]!= '#';
}

int			main(void)
{
	std::cin >> n >> m;

	for (int i(0); i < n; ++i)
		std::cin >> map[i];

	int		cnt(0);
	int		start_x, start_y, end_x, end_y, x, y;

	for (int i(0); i < n; ++i)
		for (int j(0); j < m; ++j)
			if (map[i][j] == 'S')
				start_x = j, start_y = i;
			else if (map[i][j] == 'E')
				end_y = i, end_x = j;

	std::string directions;
	std::cin >> directions;

	for (int i(0); i < 4; ++i)
	{
		dir[0] = i;
		for (int j(0); j < 4; ++j)
		{
			if (j == i)
				continue ;
			dir[1] = j;
			for (int k(0); k < 4; ++k)
			{
				if (k == i or k == j)
					continue ;
				dir[2] = k;
				for (int l(0); l < 4; ++l)
				{
					if ( l == i or l == j or l == k)
						continue ;
					dir[3] = l;
					bool	correct = true;
					x = start_x, y = start_y;
					for (auto c : directions)
					{
						x += DX[dir[c - '0']], y += DY[dir[c - '0']];
						if (!is_safe(y, x))
						{
							correct = false;
							break;
						}
						if (y == end_y and x == end_x)
							break;
					}
					if (y != end_y or x != end_x)
						correct = false;
					cnt += correct;
				}
			}
		}
	}
	std::cout << cnt << std::endl;
}