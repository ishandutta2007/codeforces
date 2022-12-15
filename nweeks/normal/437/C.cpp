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

const int	MAX = 1000;
int			c[MAX];
vi	G[MAX];

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int		n,m;
	std::cin>>n>>m;
	ll	ans(0);
	for (int i(0); i < n; ++i) std::cin >> c[i];
	for (int i(0); i < m; ++i)
	{
		int		a,b;
		std::cin>>a>>b;
		--a,--b;
		ans+=std::min(c[a],c[b]);
	}
	pnl(ans);

}