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
	
	int	N;
	read(N);

	vi	arr(N);
	vii sorted(N);
	vi	next(N);
	vi	prev(N);

	FOR(i,0,N)
	{
		prev[i] = i-1;
		next[i] = i+1;

		read(arr[i]);
		sorted[i] = {arr[i], i};
	}

	std::sort(all(sorted));

	ll	ans(0);

	int	left(0), right(N - 1);
			
	sorted.pop_back();
	if (!sorted.empty())
	sorted.pop_back();

	FORR(v, sorted)
	{
		if (v.second == left)
		{
			ans += v.first;
			left = next[left];
			continue ;
		}
		if (v.second == right)
		{
			ans += v.first;
			right = prev[right];	
			continue ;
		}

		ans += std::min(arr[prev[v.second]], arr[next[v.second]]);

		prev[next[v.second]] = prev[v.second];
		next[prev[v.second]] = next[v.second];
	}

	pnl(ans);
}