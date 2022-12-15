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

int	sq(int x) {return x * x;}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n, m;
	std::cin >> n >> m;
	int	cnt(0);
	FOR(a,0,1001) FOR(b,0,1001)
		if (sq(a)+b==n and a+sq(b)==m) ++cnt;
	pnl(cnt);
}