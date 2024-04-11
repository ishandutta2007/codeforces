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

int	N;
vs	a;

bool	is_same(std::string s1, std::string s2, int d1, int d2)
{
	for (int i(0); i < s1.size(); ++i)
		if (s1[(i + d1) % s1.size()] != s2[(i + d2) % s2.size()])
			return false;
	return true;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> N;
	a.resize(N);
	for (auto &v : a) std::cin >> v;


	int		min(1e9);

	for (int i(0); i < a[0].size(); ++i)
	{
		int		cost(i);
		for (int j(1); j < N; ++j)
		{
			if (a[0].size() != a[j].size())
			{
				pnl(-1);
				return 0;
			}
			int	k(0);
			for (; k < a[0].size(); ++k)
				if (is_same(a[0], a[j], i, k))
					break ;
			if (!is_same(a[0], a[j], i, k))
			{
				pnl(-1);
				return 0;
			}
			cost += k;
		}
		min = std::min(cost, min);
	}
	pnl(min);}