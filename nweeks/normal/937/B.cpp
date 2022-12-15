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

int	p, y;

bool	is_prime(ll n)
{
	for (ll i(2); i * i <= n and i <= p; ++i)
		if (n % i == 0)
			return false;
	return true;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> p >> y;

	for (ll i(y); i > p; --i)
		if (is_prime(i))
		{
			pnl(i);
			return 0;
		}
	pnl(-1);
}