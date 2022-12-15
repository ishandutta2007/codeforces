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


int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	c, v0, v1, a, l;
	std::cin >> c >> v0 >> v1 >> a >> l;

	int	pages_read = 0;
	int	cur_speed = v0;
	int	i(0);
	for (; pages_read < c; ++i)
	{
		pages_read += (cur_speed - (i == 0 ? 0 : l));
		cur_speed = std::min(v1, cur_speed + a);
	}
	pnl(i);
}