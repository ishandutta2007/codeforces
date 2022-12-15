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


const int	MAX = 2e4 + 1;

int			shortest[MAX];
int			target;
bool		visiting[MAX];

int			compute(int from)
{
	if (from < 0 or from > MAX or visiting[from])
		return 1e9;
	if (shortest[from] != -1)
		return shortest[from];
	visiting[from] = true;
	(shortest[from] = 1 + std::min(compute(from-1),compute(from*2)));
	visiting[from] = false;
	return shortest[from];
	
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	FOR(i,0,MAX) shortest[i] = -1;
	int	from;
	std::cin>>from>>target;
	shortest[target] = 0;
	pnl(compute(from));
}