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
	int	a, b;
	std::cin >> a >> b;
	if (a < b)
		std::swap(a,b);

	if (a == 1)
		pnl("1/1");
	if (a == 2)
		pnl("5/6");
	if (a == 3)
		pnl("2/3");
	if (a == 4)
		pnl("1/2");
	if (a == 5)
		pnl("1/3");
	if (a == 6)
		pnl("1/6");
}