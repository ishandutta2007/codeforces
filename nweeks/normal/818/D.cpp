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

const int	MAX = 1e6+1;

bool	ok[MAX];
int		occ[MAX] = {};
int		main(void)
{
	std::ios_base::sync_with_stdio(false);

	ok[0] = false;
	for (int i(1); i < MAX; ++i)
		ok[i] = true;

	std::set<ii>	set;

	int	n, A;
	std::cin >> n >> A;

	vi	colors(n);
	for (auto &v : colors)
	{
		std::cin >> v;
		set.insert({0,v});
	}

	for (int i(0); i < n; ++i)
	{
			
		int	cur = colors[i];

		if (!ok[cur])
			continue ;
		auto it = set.find({occ[cur], cur});
		set.insert({it->first+1, cur});
		set.erase(it);
		++occ[cur];

		if (cur == A)
		{
			auto ite = set.begin();
			while (ite != set.end())
			{
				if (ite->first < occ[A])
				{
					auto next = ite;
					++next;
					ok[ite->second] = false;
					set.erase(ite);
					ite = next;
				}
				else
					break ; 
			}
		}
	}


	for (auto v : set)
	{
		if (v.second != A)
		{
			pnl(v.second);
			return 0;
		}
	}
	pnl(-1);
}