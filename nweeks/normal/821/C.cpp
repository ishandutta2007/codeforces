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

const int	MAXN = 3e5;

int			arr[MAXN];

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	n; std::cin >> n;

	int	ans(0);
	int	cur(1);
	int	top(0);
	std::stack<int>	stack;
	for (int i(0); i < 2 * n; ++i)
	{
		std::string s; std::cin >> s;

		if (s == "remove")
		{
			if (top != 0)
			{
				if (arr[top-1] != cur)
					++ans, top = 0;
				else
					--top;
			}
			++cur;
		}
		else
		{
			int	a; std::cin >> a;
			arr[top++] = a;
		}

	}
	pnl(ans);

}