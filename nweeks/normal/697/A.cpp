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
	int		t, s, x;
	std::cin >> t >> s >> x;

	if (x < t)
	{
		pnl("NO");
		return 0;
	}
	if (x == t)
	{
		pnl("YES");
		return 0;
	}
	x -= t;
	
	if (x < s)
	{
		pnl("NO");
		return 0;
	}

	if (x % s == 0 or (x-1+s) % s== 0)
		pnl("YES");
	else
		pnl("NO");
}