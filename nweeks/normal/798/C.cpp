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

const int	MAX_N = 1e5;

int			a[MAX_N];
int			N;
int		gcd(void)
{
	int	pgcd = a[0];
	for (int i(1); i < N; ++i)
		pgcd = std::__gcd(pgcd, a[i]);
	return pgcd;

}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> N;

	FOR(i,0,N) std::cin >> a[i];

	if (gcd() != 1)
	{
		pnl("YES");
		pnl(0);
		return 0;
	}

	int	ans(0);
	FOR(i,0,N)
	{
		if (a[i] % 2 == 1)
		{
			if (i == 0)
			{
				if (a[i+1] % 2 == 0)
					ans += 2;
				else
					ans ++, a[i+1]=0;
			}
			else if (i == N - 1)
				ans += 2;
			else
			{
				if (a[i+1] % 2 == 1)
					ans++, a[i+1] = 0;
				else
					ans += 2, a[i+1] = 0;
			}
		}
	}
	pnl("YES");
	pnl(ans);

}