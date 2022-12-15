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
	int		n, d, a, b;
	std::cin >> n >> d >> a >> b;
	std::vector<std::pair<ll, int> > vec(n);

	for (int i(0); i < n; ++i)
	{
		int	x,y;
		std::cin >> x >> y;
		vec[i].first = (ll)x*a + (ll)y*b;
		vec[i].second = i + 1;
	}
	std::sort(all(vec));

	ll summ(0);
	int		cur(0);
	while (cur < n and (summ += vec[cur].first) <= d)
		++cur;
	pnl(cur);
	FOR(i,0,cur)
		std::cout << vec[i].second << " ";
	std::cout << std::endl;
}