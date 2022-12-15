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

std::string s;
int		occu[26] = {};
std::list<int>	pos[26];

double	best_p(int letter)
{
	int	cnt[26];
	int	max(0);
	for (int i(0); i < s.size(); ++i)
	{
		FOR(i,0,26) cnt[i] = 0;

		for (auto v : pos[letter])
			cnt[s[(v+i)%s.size()]-'a']++;
		
		int	cur(0);

		for (int k(0); k < 26; ++k)
			cur += cnt[k]==1;
		max = std::max(cur, max);
	}
	return max;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	
	read(s);

	FOR(i,0,s.size())
		occu[s[i]-'a']++, pos[s[i]-'a'].pb(i);

	double	p = 0.0;

	FOR(i, 0, 26)
	{
		if (occu[i] == 0) continue ;

		p += best_p(i) / s.size();
	}
	
	std::cout << std::setprecision(12) <<std::fixed << p << std::endl;
}