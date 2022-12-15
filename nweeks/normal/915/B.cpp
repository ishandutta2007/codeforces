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
	int		n, cur, l, r;
	std::cin >> n >> cur >> l >> r;

	int		t = 0;
	if (l == 1 and r == n)
	{
		pnl(0);
		return 0;
	}
	if (l == 1)
	{
		pnl((fabs(cur - r) + 1));
		return 0;
	}
	if (r == n)
	{
		pnl((fabs(cur - l)) + 1);
		return 0;
	}
	if (r == l)
	{
		pnl((fabs(cur - l) + 2));
		return 0;
	}
	if (fabs(cur - l) <=  fabs(cur - r))
		pnl((int)(fabs(cur - l) + fabs(r - l) + 2));
	else
		pnl((int)(fabs(cur - r) + fabs(r - l) + 2));
}