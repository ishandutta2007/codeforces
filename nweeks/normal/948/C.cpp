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

vl	snow_pile;
vl	melt;
int N;

int		main(void)
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
	read(N);
	snow_pile.resize(N);
	melt.resize(N);
	readv(snow_pile);
	readv(melt);

	vl	summ(N);

	summ[0] = melt[0];
	for (int i(1); i < N; ++i)
		summ[i] = melt[i] + summ[i-1];

	vl	ans(N, 0);
	ll	rem = 0;
	
	vl	add(N,0);

	for (int i(0); i < N; ++i)
	{
		int	left(i), right(N);
		while (left < right)
		{
			int	middle = (left+right)/2;
			if (summ[middle] - rem >= snow_pile[i])
				right = middle;
			else
				left = middle+1;
		}
		add[i]++;
		if (right == N)
			;
		else if (summ[right] == snow_pile[i])
		{
			if (left != N-1)
				add[left+1]--;
		}
		else
		{
			add[left]--;
			ans[right] += snow_pile[i] - (right?summ[right-1]-rem:0); 
		}
		
		rem = summ[i];
	}

	int	cnt(0);

	for (int i(0); i < N; ++i)
	{
		cnt += add[i];
		//std::cout << cnt << ' ' << ans[i] << std::endl;
		pns(cnt * melt[i] + ans[i]);
	}

}