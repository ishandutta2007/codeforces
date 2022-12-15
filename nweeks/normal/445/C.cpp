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

const int	MAXN = 500;

int			id[MAXN];
int			val_nodes[MAXN] = {};


int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n, m;
	std::cin >> n >> m;
	
	FOR(i,0,n) std::cin >> val_nodes[i];
	
	double	ans = 0.0;
	
	FOR(i,0,m)
	{
		int	a, b, c;
		std::cin >> a >> b >> c;
		--a, --b;
		ans = std::max((val_nodes[a]+(double)val_nodes[b]) / c, ans);
	}

	std::cout.precision(10);
	std::cout << std::fixed << ans << std::endl;
}