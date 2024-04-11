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

const int	MAX = 1e5;


int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n, m;
	std::cin >> n >> m;

	vi	a(n);
	for (auto &v : a) std::cin >> v;
	std::sort(all(a));
	int	cur(1);
	std::list<int>	to_buy;
	int	p(0);
	while (cur <= m)
	{
		if (p < n and cur == a[p])  ++p;
		else	m -= cur, to_buy.pb(cur);
		++cur;
	}

	pnl(to_buy.size());
	for (auto v: to_buy)
		std::cout << v << " ";
	std::cout << std::endl;
}