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

struct S
{
	int	a,b;
	
	bool	operator<(S other) const
	{
		return a < other.a or (a == other.a and b < other.b);
	}
};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int		n;
	std::cin >> n;

	std::vector<S>	a(n);
	for (auto &v : a)
		std::cin >> v.a>>v.b;
	std::sort(all(a));
	int	cur(0);
	int	max(0);
	
	while (cur < n)
	{
		if (a[cur].b < max)
		{
			pnl("Happy Alex");
			return 0;
		}
		int	i(cur);
		while (i < n and a[i].a == a[cur].a)
			max = std::max(a[i].b, max), ++i;
		cur = i;
	}
	pnl("Poor Alex");
}