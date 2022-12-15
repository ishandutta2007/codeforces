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
	int	a,b;
	std::cin>>a>>b;
	
	int		cnt[2][3] = {};

	while (a % 2 == 0)
		cnt[0][0]++, a /= 2;
	while (a % 3 == 0)
		cnt[0][1]++, a /= 3;
	while (a % 5 == 0)
		cnt[0][2]++, a /= 5;
	
	while (b % 2 == 0)
		cnt[1][0]++, b /= 2;
	while (b % 3 == 0)
		cnt[1][1]++, b /= 3;
	while (b % 5 == 0)
		cnt[1][2]++, b /= 5;

	if (a != b)
	{
		pnl(-1);
		return 0;
	}
	int		total(0);
	FOR(i,0,3)
		total += fabs(cnt[1][i]-cnt[0][i]);
	pnl(total);
}