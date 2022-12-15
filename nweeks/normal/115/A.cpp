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


const int	MAX = 2e3 + 1;
int			par[MAX];

int		dfs(int i)
{
	return (par[i] == -1) ? 1 : 1 + dfs(par[i]);
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n;
	std::cin >> n;
	FOR(i,1,n+1)
		std::cin>>par[i];

	int		max(0);
	for (int i(1); i<=n;++i)
		max=std::max(max,dfs(i));
	pnl(max);
			}