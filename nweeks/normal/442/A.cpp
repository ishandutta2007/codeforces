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

bool	hint[10] = {};
int		id[200] = {};
ii		cards[100];

int		best = 1e9;
int		nb_cartes;

bool	ok(void)
{
	for (int i(0); i < nb_cartes; ++i)
	{
		for (int j(i+1); j < nb_cartes; ++j)
		{
			if (cards[i] == cards[j]) continue;
			if (cards[i].F != cards[j].F and (hint[cards[i].F] or hint[cards[j].F]))
				continue ;
			if (cards[i].S != cards[j].S and (hint[cards[i].S] or hint[cards[j].S]))
				continue ;
			return false;
		}
	}
	return true;
}

void	compute(int index)
{
	if (index == 10)
	{
		if (ok())
		{
			int	cnt(0);
			for (auto v : hint) cnt += v;
			best = std::min(best, cnt);
		}
		return ;
	}

	hint[index] = false;
	compute(index+1);
	hint[index] = true;
	compute(index+1);
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	
	id['R'] = 0, id['G'] = 1, id['B'] = 2, id['Y'] = 3, id['W'] = 4;

	read(nb_cartes);
	FOR(i,0,nb_cartes)
	{
		char c; int v;
		read2(c,v);
		cards[i] = {id[c], v + 4};
	}
	compute(0);
	pnl(best);
}