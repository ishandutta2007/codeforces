#include <bits/stdc++.h>

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define FORR(v, c) for (auto &v : c)
#define F first
#define S second
#define SQ(x) (x)*(x)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define dbg(x) std::cerr<<#x<<" = " << (x) << std::endl
#define pnl(x) std::cout << x << '\n'
#define pns(x) std::cout << x << ' '
#define read(x) std::cin >> x
#define read2(x,y) std::cin >> x >> y
#define read3(x, y, z) std::cin >> x >> y >> z
#define read4(a, b, c, d) std::cin >> a >> b >> c >> d
#define readv(v) FORR(c,v) read(c)

struct Arrete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

typedef	std::vector<int>	vi;
typedef std::pair<int,int>	ii;
typedef std::vector<std::string>	vs;
typedef std::vector<ii>	vii;
typedef std::vector<Arrete>	vg;
typedef std::vector<long long>	vl;
typedef	long long ll;

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

int		main(void)
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	std::set<int>	zeros, ones;

	std::string s;
	read(s);

	for (int i(0); i < s.size(); ++i)
	{
		if (s[i] == '1')
			ones.insert(i);
		else
			zeros.insert(i);
	}

	std::vector<std::list<int>>	ans;

	while (1)
	{
		if (zeros.empty())
			break ;
		std::list<int>	cur;

		int	left(*zeros.begin());
		zeros.erase(left);
		cur.pb(left);

		while (1)
		{
			auto p1 = ones.lower_bound(cur.back());
			if (p1 == ones.end())
				break;
			auto p2 = zeros.lower_bound(*p1);
			if (p2 == zeros.end())
				break;
			cur.pb(*p1);
			cur.pb(*p2);
			ones.erase(*p1);
			zeros.erase(*p2);
		}

		ans.pb(cur);
	}

	if (!ones.empty())
	{
		pnl(-1);
		return 0;
	}
	for (auto v : zeros)
		ans.pb({v});
	pnl(ans.size());
	for (auto v : ans)
	{
		pns(v.size());
		for (auto u : v)
			pns(u+1);
		std::cout << '\n';
	}
}