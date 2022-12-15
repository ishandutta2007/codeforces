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

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

int		main(void)
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	int	n;
	read(n);
	
	std::map<int, vi>	map;

	FOR(i,0,n)
	{
		int	a;
		read(a);
		map[a].pb(i);
	}
	std::list<ii>	ans;

	for (auto c : map)
	{
		auto v = c.second;
		if (v.size() == 1)
			ans.pb({c.first, 0});
		else
		{
			int	diff = 	v[1]-v[0];
			bool	ok=true;
			for (int i(1); i < v.size()-1;++i)
				if (v[i+1]-v[i]!=diff)
				{
					ok=false;
					break;
				}
			if (ok)
				ans.pb({c.F, diff});
		}

	}
	pnl(ans.size());
	FORR(v,ans)
	{
		std::cout << v.F << " " << v.S << '\n';
	}
}