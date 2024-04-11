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

bool	comp(ii a, ii b)
{
	return a.first < b.first;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	s, n;
	std::cin >> s >> n;

	vii		a(n);
	for (auto &v : a) std::cin >> v.first >> v.second;
	std::sort(all(a));

	for (auto v : a)
	{
		if (v.first >= s)
		{
			pnl("NO");
			return 0;
		}
		s += v.second;
	}
	pnl("YES");
}