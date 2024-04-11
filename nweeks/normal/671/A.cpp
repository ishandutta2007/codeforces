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

ll	sq(ll x) {return x * x;}

struct Point
{
	ll	x, y;

	double	distance(Point other) const
	{
		return sqrt(sq(x-other.x) + sq(y-other.y));
	}
};

Point	bottles[(int)1e5];
Point a_start, b_start, bin;
int	n;

double	best(Point a, Point b)
{
	int	position = -1;
	double	best = -a.distance(bin);

	for (int i(0); i < n; ++i)
		if (-a.distance(bottles[i]) + bottles[i].distance(bin) > best)
			best = -a.distance(bottles[i]) + bottles[i].distance(bin), position = i;
	
	double	other_best = 0;
	for (int i(0); i < n; ++i)
	{
		if (i == position) continue ;
		other_best = std::max(other_best, -b.distance(bottles[i]) + bottles[i].distance(bin));
	}
	return best + other_best;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);

	std::cin >> a_start.x >> a_start.y >> b_start.x >> b_start.y >> bin.x >> bin.y;

	std::cin >> n;

	for (int i(0); i < n; ++i)
		std::cin >> bottles[i].x >> bottles[i].y;

	long double summ(0);
	for (int i(0); i < n; ++i)
		summ += 2 * bottles[i].distance(bin);
	
	std::cout.precision(12);

	std::cout << std::fixed << summ - std::max(best(a_start, b_start), best(b_start, a_start)) << std::endl;
}