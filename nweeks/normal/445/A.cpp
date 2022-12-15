#include <bits/stdc++.h>

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(x) std::cerr<<#x<<" = " << (x) << std::endl
#define pnl(x) std::cout << x << "\n"

typedef	std::vector<int>	vi;
typedef std::pair<int,int>	ii;
typedef std::vector<std::string>	vs;
typedef std::vector<ii>	vii;
typedef std::vector<long long>	vl;
typedef	long long ll;


const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

const int	MAX = 100;

char		grid[MAX][MAX];
int	N, M;

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> N >> M;

	for (int i(0); i < N; ++i)
		std::cin >> grid[i];

	for (int i(0); i < N; ++i)
	{
		for (int j(0); j < M; ++j)
		{
			if (grid[i][j] == '-')
			{
				std::cout << "-";
				continue ;
			}
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
					std::cout << "W";
				else
					std::cout << "B";
			}
			else
			{
				if (j % 2 == 0)
					std::cout << "B";
				else
					std::cout << "W";
			}
		}
		std::cout << std::endl;
	}
}