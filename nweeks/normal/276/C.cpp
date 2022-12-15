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

const int	MAX = 2e5;

bool	comp(int a, int b) {return a > b;}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n, q; std::cin >> n >> q;
	vi	a(n); for (auto &v : a) std::cin >> v;
	vi	delta(n+1,0);

	FOR(i,0,q)
	{
		int	l, r;
		std::cin >> l >> r;
		--l;
		delta[l]++, delta[r]--;
	}
	
	for (int i(0); i < n-1; ++i)
		delta[i+1] += delta[i];
	delta[n] = -1e9;

	std::sort(all(delta), comp);

	std::sort(all(a), comp);

	ll	ans(0);
	FOR(i,0,n)
		ans += (ll)a[i] * delta[i];
	pnl(ans);
}