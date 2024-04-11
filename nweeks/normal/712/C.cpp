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

bool	ok(int a, int b, int c)
{
	if (a + b > c and a + c > b and b + c > a)
		return true;
	return false;
}

void	sort(int &a, int &b, int &c)
{
	if (a > b) std::swap(a,b);
	if (b > c) std::swap(b, c);
	if (a > b) std::swap(a, b);
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	x, y;
	std::cin >> x >> y;

	int	a(y), b(y), c(y);
	int	ans(0);
	while (a != x or b != x or c != x)
	{
		bool	changed = false;
		while (a != x and ok(a+1,b,c))
			a++;
		++ans;
		sort(a,b,c);
	}
	pnl(ans);
}