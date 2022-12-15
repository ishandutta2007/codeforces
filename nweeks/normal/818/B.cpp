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
	
	int	n, m;
	std::cin >> n >> m;

	vi	a(n,-1);

	int	prev;
	std::cin >> prev;

	std::set<int>	set;
	for (int i(1); i <= n; ++i) set.insert(i);

	for (int i(1); i < m; ++i)
	{
		int	cur; std::cin >> cur;
		int		next = (cur+n-prev)%n;
		if (!next) next = n;
		if (a[prev-1] != -1 and a[prev-1] != next)
		{
			std::cout << -1 << std::endl;
			return 0;
		}
		a[prev-1] = next;
		set.erase(next);
		prev = cur;
	}
	
	
	for (int i(0); i < n; ++i)
	{
		if (a[i]==-1)
		{
			a[i] = *set.begin();
			set.erase(set.begin());
		}
		for (int j(i+1); j < n; ++j)
			if (a[i] == -1 or a[i] == a[j])
			{
				std::cout << -1 << std::endl;
				return 0;
			}
	}

	for (auto v : a)
		std::cout << v << " ";
	std::cout << std::endl;
}