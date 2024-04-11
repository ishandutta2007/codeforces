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


ll		lcm(ll	a, ll b)
{
	return a*b/std::__gcd(a,b);
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);

	ll	a, b;
	std::cin >> a >> b;

	ll	p = lcm(a,b);

	ll	freq_a = p/a;
	ll	freq_b = p/b;

	if (a > b)	freq_b--;
	else		freq_a--;

	if (freq_a>freq_b)
		pnl("Dasha");
	else if (freq_a < freq_b)
		pnl("Masha");
	else
		pnl("Equal");

}