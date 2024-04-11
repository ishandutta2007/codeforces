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

bool	is_lucky(int x)
{
	while (x)
	{
		if (x % 10 != 4 and x % 10 != 7) return false;
		x /= 10;
	}
	return true;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n; std::cin >> n;

	for (int i(2); i <= n; ++i)
		if (n%i==0 and is_lucky(i))
		{
			pnl("YES");
			return 0;
		}
	pnl("NO");
}