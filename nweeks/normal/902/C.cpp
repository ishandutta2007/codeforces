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


int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int H;
	std::cin >> H;

	vi	a(H+1);
	for (auto &v : a) std::cin >> v;

	bool	perfect = true;;
	int		N(0);
	for (int i(0); i < H; ++i)
	{
		if (a[i] != 1 and a[i+1] != 1)
		{
			perfect = false;
		}
		N += a[i];
	}
	N += a[H];

	if (perfect)
	{
		pnl("perfect");
		return 0;
	}

	pnl("ambiguous");
	int	cur(1);
	int	prev(0);
	for (int i(0); i <= H; ++i)
	{
		FOR(k, 0, a[i])
			std::cout << prev << " ";
		cur += a[i];
		prev = cur - 1;

	}
	std::cout << std::endl;
	
	cur = 1;
	int	prev1 = 0, prev2 = -1;
	bool	did = false;
	for (int i(0); i <= H; ++i)
	{
		if (!did and i and a[i-1] != 1 and a[i] != 1)
		{
			std::cout << prev2 << " ";
			for (int k(1); k < a[i]; ++k)
				std::cout << prev1 << " "; 
			did = true;
		}
		else
			for (int k(0); k < a[i]; ++k)
				std::cout << prev1 << " ";
		cur += a[i];
		if (a[i] != 1)
			prev1 = cur - 1, prev2 = cur - 2;
		else
			prev1 = cur - 1;
	}
	std::cout << std::endl;


}