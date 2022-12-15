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

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin>>n;
	vi	a(n+1);
	FOR(i,0,n) std::cin>>a[i];
	int	m;
	std::cin >> m;
	
	FOR(i,0,m)
	{
		int		y, x;
		std::cin >> x >> y;
		--x;
		if (x == 0)
			a[x+1] += a[x] - y;	
		else
			a[x+1] += a[x] - y, a[x-1] += (y-1);
		a[x] = 0;
	}
	FOR(i,0,n) pnl(a[i]);

}