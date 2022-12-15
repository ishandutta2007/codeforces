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

const int MAX = 1e5+1;

int		cnt[MAX] = {};
int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	
	int	n;
	std::cin >> n;
	while (n--)
	{
		int	a; std::cin >> a;
		cnt[a]++;
	}
	for (int i(0); i < MAX; ++i)
	{
		if (cnt[i] % 2 == 1)
		{
			pnl("Conan");
			return 0;
		}
	}
	pnl("Agasa");
}