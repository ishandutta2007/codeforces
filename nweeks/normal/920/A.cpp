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

int		solve(void)
{
	int		n, k;
	std::cin >> n >> k;

	vi		best(n+1, 1e9);

	best[0] = -1;

	while (k--)
	{
		int	a; std::cin >> a;
		FOR(i,1,n+1)
		best[i] = std::min((int)fabs(a-i)+1, best[i]);
	}

	int		ans(0);
	FOR(i,1,n+1)
		ans = std::max(ans, best[i]);
	return ans;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int		t;
	std::cin >> t;

	while (t--)
		pnl(solve());
}