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

const int	MAX = 50;

int	map[MAX][MAX];

int	n;

bool	ok(int y, int x)
{
	for (int i(0); i < n; ++i)
		for (int j(0); j < n; ++j)
			if (map[y][i] + map[j][x] == map[y][x])
				return true;
	return false;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> n;
	FOR(i,0,n) FOR(j,0,n) std::cin >> map[i][j];

	for (int i(0); i < n; ++i)
		for (int j(0); j < n; ++j)
			if (map[i][j] != 1 and !ok(i, j))
			{
				pnl("No");
				return 0;
			}

	pnl("Yes");
}