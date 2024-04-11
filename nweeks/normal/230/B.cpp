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
	std::cin>>n;
	std::vector<bool>	is_prime(1e6+1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i(2); i < 1e6+1;++i)
		if (is_prime[i])
			for (int j(2*i);j<1e6+1;j+=i)
				is_prime[j]=false;

	while (n--)
	{
		ll a;std::cin>>a;
		if (a != 1 and sqrt(a)==(int)sqrt(a) and is_prime[sqrt(a)])
			pnl("YES");
		else
			pnl("NO");
	}
}