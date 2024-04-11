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

struct Point
{
	int		x, y, index;
};

bool	compx(Point a, Point b)
{
	return a.x < b.x;
}

bool	compy(Point a, Point b)
{
	return a.y < b.y;
}


bool	comp(Point a, Point b)
{
	return a.y < b.y or (a.y == b.y and a.x < b.x);
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	N;
	std::cin >> N;

	std::vector<Point>	points(N);
	for (auto&v : points)
		std::cin >> v.x >> v.y;

	long long ans = 0;	

	// x

	std::sort(all(points), compx);
	ll cur(0);
	while (cur < N)
	{
		ll right(cur);
		while (right < N and points[cur].x == points[right].x)
			++right;
		ans += ((right - cur) * (right - cur - 1)) / 2;
		cur = right;
	}

	// y

	std::sort(all(points), compy);
	cur = 0;
	while (cur < N)
	{
		ll right(cur);
		while (right < N and points[cur].y == points[right].y)
			++right;
		ans += ((right - cur-1) * (right - cur)) / 2;
		cur = right;
	}

	//all

	std::sort(all(points), comp);
	cur = 0	;
	while (cur < N)
	{
		ll right(cur);
		while (right < N and points[right].x == points[cur].x and points[right].y == points[cur].y)
			++right;
		ans -= ((right - cur - 1) * (right - cur)) / 2;
		cur = right;
	}
	pnl(ans);
}