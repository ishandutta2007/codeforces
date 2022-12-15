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

struct	Team
{
	int		total, penalty;

	bool	operator==(Team other) const
	{
		return total == other.total and penalty == other.penalty;
	}
	bool	operator<(Team other) const
	{
		return total > other.total or (total == other.total and penalty < other.penalty);
	}
};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int		n,k;
	std::cin>>n>>k;
	std::vector<Team>	teams(n);
	for (auto& v : teams)
		std::cin >> v.total >> v.penalty;
	std::sort(all(teams));

	Team	good = teams[k-1];
	int		ans(0);
	for (auto v : teams)
		ans += (good == v);
	pnl(ans);
}