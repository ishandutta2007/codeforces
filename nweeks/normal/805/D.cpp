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

const int	MOD = 1e9+7;

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::string s;
	std::cin >> s;
	ll	cnt(0);

	ll	consecutive_a = 1;
	for (int i(0); i < s.size(); ++i)
	{
		if (s[i] == 'a')
			consecutive_a = (consecutive_a * 2) % MOD;
		else
			cnt = (cnt + consecutive_a - 1) % MOD;
	}
	pnl(cnt);
}