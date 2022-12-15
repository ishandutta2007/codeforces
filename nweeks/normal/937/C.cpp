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

ll	k, d;

long double t;

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> k >> d >> t;

	ll	ans = t / (k+((d - k%d)%d)/2.0);

	ll	time_spent = ans * (k+(d-k%d)%d);

	t -= ans * (k+((d - k%d)%d)/2.0);

	std::cout.precision(10);

	if (t <= k)
		std::cout << std::fixed << time_spent + t << std::endl;
	else
		std::cout << std::fixed << (double)(time_spent + k + (t-k)*2) << std::endl;

}