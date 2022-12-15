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

const int	MAX = 2000;

bool		map[MAX][MAX];
int			n, m, k;

ll	count_hori(void)
{
	ll	ans(0);
	FOR(i,0,n)
	{
		int		consecutive(0);
		for (int j(0); j < m; ++j)
		{
			if (map[i][j]) ++consecutive;
			else
			{
				consecutive -= k;
				ans += std::max(0, consecutive+1);
				consecutive = 0;
			}
		}
		consecutive -= k;
		ans += std::max(0, consecutive+1);
	}
	return ans;
}

ll	count_verti(void)
{
	ll	ans(0);
	FOR(i,0,m)
	{
		int		consecutive(0);
		for (int j(0); j < n; ++j)
		{
			if (map[j][i]) ++consecutive;
			else
			{
				consecutive -= k;
				ans += std::max(0, consecutive+1);
				consecutive = 0;
			}
		}
		consecutive -= k;
		ans += std::max(0, consecutive+1);
	}
	return ans;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> n >> m >> k;
	FOR(i,0,n) FOR(j,0,m)
	{
		char	c; std::cin >> c;
		map[i][j] = (c == '.');
	}
	if (k == 1)
	{
		ll	ans(0);
		FOR(i,0,n) FOR(j,0,m)
		ans += map[i][j];
		pnl(ans);
		return 0;
	}
	
	pnl(count_verti() + count_hori());
}