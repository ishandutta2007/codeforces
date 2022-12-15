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

const int	MAX_SIZE = (1<<19);

int			count[MAX_SIZE] = {};

ll			dec_to_bin(ll n)
{
	ll	ret = 0;
	std::string s = std::to_string(n);
	for (auto c : s)
		ret = ret * 2 + (c-'0')%2;
	return ret;
}

ll			bin_to_ll(std::string s)
{
	ll	ret(0);
	for (auto c : s)
		ret = ret * 2 + (c-'0');
	return ret;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	t;
	std::cin >> t;

	while (t--)
	{
		char c; std::cin >> c;

		if (c == '+')
		{
			ll	n; std::cin >> n;
			count[dec_to_bin(n)]++;
		}
		else if (c == '-')
		{
			ll	n; std::cin >> n;
			count[dec_to_bin(n)]--;
		}
		else
		{
			std::string s; std::cin >> s;
			pnl(count[bin_to_ll(s)]);
		}
	}

}