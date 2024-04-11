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

struct Arrete { int v, c;};
struct Point {int x, y; double distance(Point other) const {return sqrt(SQ(x-other.x)+SQ(y-other.y));}};

typedef	std::vector<int>	vi;
typedef std::pair<int,int>	ii;
typedef std::vector<std::string>	vs;
typedef std::vector<ii>	vii;
typedef std::vector<Arrete>	vg;
typedef std::vector<long long>	vl;
typedef	long long ll;

const int	MAXN = 26;

int	id[MAXN];

int	find(int i) {return id[i] == i ? i : id[i] = find(id[i]);}

void	merge(int a, int b)
{
	id[find(b)] = find(a);
}


int		main(void)
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	FOR(i,0,26) id[i] = i;

	int	n;
	read(n);
	std::string a, b;
	read2(a, b);

	std::vector<std::pair<char, char > > ans;

	FOR(i,0,n)
		if (a[i] != b[i] and find(a[i]-'a') != find(b[i]-'a'))
			merge(a[i]-'a', b[i]-'a'), ans.pb({a[i],b[i]});

	pnl(ans.size());

	FORR(v, ans)
		std::cout << v.F << ' ' << v.S << std::endl;

}