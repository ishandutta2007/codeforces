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

bool	is_prime(ll	a)
{
	ll 	born = sqrt(a);
	for (int i(2); i <= born;++i)
		if (a%i==0)
			return false;
	return true;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	ll	n;
	std::cin >> n;

	ll	ans(1);
	ll	born(sqrt(n));
	for (int i(1); i <= born; ++i)
	{
		if (n % i == 0)
		{
			if (is_prime(i))
				ans *= i;
			if (n / i != i and is_prime(n/i))
				ans *= n/i;
		}
	}
	pnl(ans);
}