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

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n;
	std::cin >> n;

	vl	a(n);
	std::string b;
	for (auto &v : a) std::cin >> v;
	std::cin >> b;

	ll	left(-1e9), right(1e9);

	for (int i(4); i < n; ++i)
	{
		if (!(b[i-1] == b[i-2] and b[i-1] == b[i-3] and b[i-1] == b[i-4]))
			continue ;
		if (b[i-1] == '1')
		{
			ll min = 1e9;
			for (int j(i); j >= i-4; --j)
				min = std::min(a[j], min);
			if (b[i] == '0')
			{
				if (right >= min)
					right = min - 1;
			}
			else
			{
				if (right < min)
					right = min;
			}
		}
		else
		{
			ll	max = -2e9;
			for (int j(i); j >= i-4; --j)
				max = std::max(a[j], max);
			if (b[i] == '1')
			{
				if (left <= max)
					left = max+1;
			}
			else
			{
				if (left > max)
					left = max;
			}
		}
	}

	std::cout << left << " " << right << std::endl;
}