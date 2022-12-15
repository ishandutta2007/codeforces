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

struct Problem
{
	int	a, t, index;

	bool	operator<(Problem other) const
	{
		return t < other.t;
	}
};

int	n, T;
std::vector<Problem>	problems;

bool	ok(int max)
{
	int	cnt(0);
	int	t(0);
	for (int i(0); i < n and cnt < max; ++i)
		if (problems[i].a>= max)
			++cnt, t += problems[i].t;
	if (cnt < max or t > T)
		return false;
	return true;
}

void	output(int max)
{
	pnl(max),pnl(max);

	int	cur(0);
	for (int i(0); cur < max; ++i)
		if (problems[i].a >= max)
			++cur, std::cout << problems[i].index << " ";
	std::cout << std::endl;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> n >> T;
	problems.resize(n);
	for (int i(1); i <= n; ++i)
	{
		std::cin >> problems[i-1].a >> problems[i-1].t;
		problems[i-1].index = i;
	}

	std::sort(all(problems));


	int	left(0), right(n);
	while (left < right)
	{
		int	mid = (1+left + right) / 2;
		if (ok(mid))
			left = mid;
		else
			right = mid - 1;
	}
	output(left);
}