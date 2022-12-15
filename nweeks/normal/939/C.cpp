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

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

const int	MAXN = 1e5 + 1;

int	summ[MAXN] = {};
int	N;

int	get_summ(int l, int r)
{
	if (r > N)
		r -= N;
	if (l <= r)
		return summ[r] - summ[l-1];
	else
		return summ[r] + summ[N] - summ[l-1];
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

	read(N);

	FOR(i,1,N+1)
	{
		read(summ[i]);
		summ[i]+=summ[i-1];
	}

	int s, f;
	read2(s, f);
	int	range = f - s -1;

	int	max(0), max_t(0);

	for (int i(1); i <= N; ++i)
		if (get_summ(i, i+range) >= max)
		{
			int	t = s-i+1;
			if (t <= 0)
				t += N;
			if (get_summ(i, i+range) == max)
				max_t = std::min(t, max_t);
			else
				max = get_summ(i, i+range), max_t = t;
		}
	pnl(max_t);
}