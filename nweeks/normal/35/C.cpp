#include <bits/stdc++.h>

#define FOR(i, j, n) for (int i(j); i < n; ++i)
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define dbg(x) std::cerr<<#x<<" = " << (x) << std::endl
#define pnl(x) std::cout << x << "\n"

typedef	std::vector<int>	vi;
typedef std::pair<int,int>	ii;
typedef std::vector<std::string>	vs;
typedef std::vector<ii>	vii;
typedef std::vector<long long>	vl;
typedef	long long ll;


const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

int		n,m;

struct S
{
	int		y, x, d;
};

bool	is_safe(int y, int x)
{
	return y >= 0 and x >= 0 and y < n and x < m;
}


int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::ofstream	out;
	std::ifstream	in;
	in.open("input.txt");
	out.open("output.txt");

	in>>m>>n;
	int	M;
	in>>M;
	vii	a(M);
		

	FOR(i,0,M)
		in>>a[i].second>>a[i].first;
	S	best = {0,0,-1};

	FOR(i,1,n+1) FOR(j,1,m+1)
	{
		int	min_dist = 1e9;
		for (auto v : a)
			min_dist = std::min(min_dist, (int)fabs(i-v.first) + (int)fabs(j-v.second));
		if (min_dist>best.d)
			best={j,i,min_dist};
	}
	out		<< best.y << " " << best.x  << std::endl;
}