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

const int	MAX = 1001;


bool		exists[MAX] = {};
int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n;
	std::cin >> n;

	while (n--)
	{
		int	a; std::cin >> a; exists[a] = true;
	}

	for (int i(0); i < MAX - 2; ++i)
		if (exists[i] and exists[i+1] and exists[i+2])
		{
			pnl("YES");
			return 0;
		}


	pnl("NO");
}