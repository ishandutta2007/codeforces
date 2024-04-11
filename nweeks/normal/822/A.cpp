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

ll	fact(ll n)
{
	ll	ret = 1;
	FOR(i,2,n+1)
		ret *= i;
	return ret;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	ll	A, B;
	std::cin >> A >> B;
	if (A < B)
		pnl(fact(A));
	else
		pnl(fact(B));
}