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

const int	MAX = 5e5;

int			w[MAX];
int			N, k;

bool	ok_min(int min)
{
	ll	cnt(0);
	for (int i(0); i < N; ++i)
		if (w[i] < min)
			cnt += min-w[i];
	return cnt <= k;
}

bool	ok_max(int max)
{
	ll	cnt(0);
	for (int i(0); i < N; ++i)
		if (w[i] > max)
			cnt += w[i] - max;
	return cnt <= k;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false); std::cin.tie(0);
	std::cin >> N >> k;

	ll	tot = 0;
	for (int i(0); i < N; ++i)
	{
		std::cin >> w[i];
		tot += w[i];
	}

	int	left(0), right(1e9);

	while (left +1< right)
	{
		int	mid = (left + right) / 2;
		if (ok_min(mid))
			left = mid;
		else
			right = mid;
	}
	
	int	min_bound = left;

	int	left2(0), right2(1e9);
	while (left2 +1< right2)
	{
		int	mid = (left2+right2)/2;
		if (ok_max(mid))
			right2 = mid;
		else
			left2 = mid;
	}

	int	max_bound = left2+1;


	if (min_bound > max_bound-2)
		pnl(!!(tot%N));
	else
		pnl(max_bound - min_bound);


}