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
	std::vector<ll>	v(n + 1, 0);
	std::vector<ll>	u(n + 1, 0);
	FOR(i,1,n+1)
	{
		std::cin >> v[i];
		u[i] = v[i];
	}
	std::sort(all(u));
	FOR(i,0,n)
		v[i+1]+=v[i], u[i+1]+=u[i];

	int		Q;
	std::cin >> Q;
	while (Q--)
	{
		int	t, l, r;
		std::cin>>t>>l>>r;
		if (t == 1)
			pnl(v[r] - v[l - 1]);
		else
			pnl(u[r] - u[l - 1]);
	}
}