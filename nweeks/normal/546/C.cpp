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
	int		n;
	std::cin >> n;
	std::queue<int>	a;
	std::queue<int>	b;

	int	k;
	std::cin >> k;
	while (k--)
	{
		int	val; std::cin >> val;
		a.push(val);
	}
	std::cin>>k;
	while (k--)
	{
		int	val; std::cin >> val;
		b.push(val);
	}

	int		cnt(0);
	while (cnt < 1e5 and !a.empty() and !b.empty())
	{
		cnt++;
		int		f = a.front(); a.pop();
		int		s = b.front(); b.pop();
		if (f > s)
			a.push(s), a.push(f);
		else
			b.push(f), b.push(s);
	}
	if (!a.empty() and !b.empty())
	{
		pnl(-1);
		return 0;
	}
	if (a.empty())
		std::cout << cnt << " " << 2 << std::endl;
	else
		std::cout << cnt << " " << 1 << std::endl;
}