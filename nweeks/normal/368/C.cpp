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

const int	MAX = 1e5+1;

int	x[MAX] = {};
int y[MAX] = {};
int	z[MAX] = {};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	
	std::string s;
	std::cin >> s;
	for (int i(0); i < s.size(); ++i)
	{
		if (s[i] == 'x') x[i+1]++;
		if (s[i] == 'y') y[i+1]++;
		if (s[i] == 'z') z[i+1]++;
		x[i+1]+=x[i];
		y[i+1]+=y[i];
		z[i+1]+=z[i];
	}

	int	q;
	std::cin >> q;
	while (q--)
	{
		int	l, r;
		std::cin >> l >> r;
		int	xc = x[r]-x[l-1];
		int	yc = y[r] - y[l-1];
		int zc = z[r] - z[l-1];
		int	min = std::min(xc, std::min(yc,zc));
		xc -= min, yc -= min, zc -= min;
		
		if ((r-l+1) >= 3 and (xc >=2 or yc>=2 or zc >=2))
			pnl("NO");
		else
			pnl("YES");

	}

}