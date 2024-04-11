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

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	ll	ans(1);

	bool	used[51] = {};

	int	n, m;
	std::cin >> n >> m;


	vii	a(m);
	for (auto &v : a) std::cin >> v.first >> v.second;

	used[1] = true;

	for (int i(1); i < n; ++i)
	{
		bool	found_one = false;
		for (auto v : a)
		{
			if (used[v.first] and !used[v.second])
			{
				found_one = true;
				used[v.second] = true;
				break;
			}
			else if (!used[v.first] and used[v.second])
			{
				found_one = true;
				used[v.first] = true;
				break ;
			}
		}
		if (found_one)
			ans *= 2;
		else
		{
			for (int i(1); i <= n; ++i)
			{
				if (!used[i])
				{
					used[i] = true;
					break;
				}
			}
		}
	}
	pnl(ans);
}