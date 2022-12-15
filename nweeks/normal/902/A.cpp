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

const int	MAXN = 201;

int	m, n;

bool	can[MAXN] = {};

struct Event
{
	int	x;
	int	delta;

	bool	operator<(Event other) const
	{
		return x < other.x or (x == other.x and delta == 1);
	}
};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> n >> m;
	
	can[0] = true;
	for (int i(0); i < n; ++i)
	{
		int	a, b;
		std::cin >> a >> b;
		if (can[a])
			for (int i(a+1); i <= b; ++i)
				can[i] = true;
	}

	if (can[m])
		pnl("YES");
	else
		pnl("NO");
}