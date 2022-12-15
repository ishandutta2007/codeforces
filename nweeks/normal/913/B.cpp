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
const int		MAX = 1000;

std::vector<int>	childs[MAX];

int		main(void)
{
	std::ios_base::sync_with_stdio(false);

	int		n;
	std::cin >> n;
	for (int i(1); i < n ; ++i)
	{
		int		a;
		std::cin >> a;
		--a;
		childs[a].push_back(i);
	}

	bool	is_leaf[MAX] = {};
	for (int i(0); i < n; ++i)
		is_leaf[i] = (childs[i].size() == 0);
	for (int i(0); i < n; ++i)
	{
		int	cnt(0);
		for (auto v : childs[i])
		{
			cnt += is_leaf[v];
		}
		if (!is_leaf[i] and cnt < 3)
		{
			pnl("No");
			return 0;
		}
	}
	pnl("Yes");
}