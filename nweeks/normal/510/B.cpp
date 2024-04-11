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

const int	MAX = 50;

char	map[MAX][MAX];
int		discovered[MAX][MAX] = {};
int		n,m;
bool	found(false);

bool	is_safe(int y,int x)
{
	return y >= 0 and x >= 0 and y < n and x < m;
}

void	DFS(int y, int x, int cnt)
{
	char	c = map[y][x];
	discovered[y][x]=cnt;
	map[y][x] = '.';

	FOR(d, 0, 4)
	{
		if (is_safe(y+DY[d],x+DX[d]))
		{
			if (map[y+DY[d]][x+DX[d]]==c)
				DFS(y+DY[d],x+DX[d],cnt+1);
			if (map[y+DY[d]][x+DX[d]]=='.' and cnt -discovered[y+DY[d]][x+DX[d]] >= 3)
			{
				pnl("Yes");
				exit(0);
			}
		}
	}

	map[y][x] = c;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin>>n>>m;
	FOR(i,0,n)
		std::cin>>map[i];
	FOR(i,0,n) FOR(j,0,m) DFS(i,j,0);
	pnl("No");
}