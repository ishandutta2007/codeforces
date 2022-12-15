#include <bits/stdc++.h>

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define FORR(v, c) for (auto &v : c)
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(x) std::cerr<<#x<<" = " << (x) << std::endl
#define pnl(x) std::cout << x << "\n"
#define read(x) std::cin >> x
#define read2(x,y) std::cin >> x >> y
#define read3(x, y, z) std::cin >> x >> y >> z
#define read4(a, b, c, d) std::cin >> a >> b >> c >> d

typedef	std::vector<int>	vi;
typedef std::pair<int,int>	ii;
typedef std::vector<std::string>	vs;
typedef std::vector<ii>	vii;
typedef std::vector<long long>	vl;
typedef	long long ll;

struct Arrete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

int		main(void)
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
		

	int	n;
	read(n);

	vii	trees(n);
	FORR(v, trees)
		read2(v.F, v.S);

	int	ans(1);
	int	prev = trees[0].F;
	
	FOR(i,1,n)
	{
		if (trees[i].F - trees[i].S > prev)
		{
			ans++;
			prev = trees[i].F;
		}
		else if ((i == n - 1) or (trees[i].F + trees[i].S < trees[i+1].F))
		{
			ans++;
			prev = trees[i].F + trees[i].S;
		}
		else
			prev = trees[i].F;
	}
	pnl(ans);
}