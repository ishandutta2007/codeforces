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


int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n;
	std::cin >> n;

	FOR(i,0,n) FOR(j,0,n)
	{
		int	dis = fabs(n/2-i) + fabs(n/2-j);
		if (dis <= n/2) std::cout << "D";
		else			std::cout << "*";
		if (j == n-1) std::cout << "\n";
	}
}