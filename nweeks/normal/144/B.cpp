#include <bits/stdc++.h>

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define FORR(v, c) for (auto &v : c)
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(x) std::cerr<<#x<<" = " << (x) << std::endl
#define pnl(x) std::cout << x << '\n'
#define pns(x) std::cout << x << ' '
#define read(x) std::cin >> x
#define read2(x,y) std::cin >> x >> y
#define read3(x, y, z) std::cin >> x >> y >> z
#define read4(a, b, c, d) std::cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

typedef	std::vector<int>	vi;
typedef std::pair<int,int>	ii;
typedef std::vector<std::string>	vs;
typedef std::vector<ii>	vii;
typedef std::vector<long long>	vl;
typedef	long long ll;

struct Arrete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

struct Radiateur {Point a; int r;};

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

int		main(void)
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	
	Point a, b;
	read4(a.x,a.y,b.x,b.y);

	int	n;
	read(n);
	std::vector<Radiateur>	r(n);

	FORR(v,r)
		read3(v.a.x,v.a.y,v.r);
	
	if (a.x > b.x) std::swap(a.x,b.x);
	if (a.y>b.y) std::swap(a.y,b.y);
	
	int	ans(0);
	FOR(i,a.y,b.y+1)
		FOR(j,a.x,b.x+1)
	{
		if (i!= a.y and i!=b.y and j!=a.x and j!=b.x)
			continue;
		bool	ok(false);
		FORR(v,r)
			if (v.a.distance({j,i}) <= v.r)
				ok=true;
		ans +=!ok;
	}
	pnl(ans);
}