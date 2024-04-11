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

ll	sq(ll x) {return x * x;}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	ll	n, x, y;
	std::cin >> n >> x >> y;

	if (n > y)
	{
		pnl(-1);
		return 0;
	}

	if (n - 1 + sq(y - (n-1)) < x)
		pnl(-1);
	else
	{
		FOR(i,1,n) pnl(1);
		pnl(y - (n-1));
	}
}