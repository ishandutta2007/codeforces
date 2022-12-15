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

int	min = 1e9;
std::list<int>	min_list;


int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	
	int n, m; std::cin >> n >> m;

	std::string s, t;
	std::cin >> s >> t;

	for (int i(0); i < t.size() - n+1; ++i)
	{
		int	p1 = 0, p2 = i;
		std::list<int>	rem;
		
		while (p1 < s.size())
		{
			if (s[p1] != t[p2])
				rem.pb(p1+1);
			++p1, ++p2;
		}
		if (min > rem.size())
			min_list = rem, min = rem.size();
	}
	std::cout << min << std::endl;
	for (auto v : min_list)
		std::cout << v << " ";
	std::cout << std::endl;
}