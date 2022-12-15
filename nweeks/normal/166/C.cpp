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
vi			a;

int		compute(int N, int X, int rank)
{
	int	ans(0);	

	while ((N + 1) / 2 != rank)
	{
		if (rank > (N+1)/2)
			++N;
		else
			++N, ++rank;
		++ans;
	}
	return ans;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int		N, X;
	std::cin >> N >> X;
	a.resize(N);
	for (auto &v : a)
		std::cin >> v;
	std::sort(all(a));

	int	ans(1e9);
	int	rank = 0;

	while (rank < N and a[rank] < X)
		++rank;
	
	if (rank == N or a[rank] != X)
		ans = 1 + compute(N+1, X, rank + 1);
	for (int i(0); i < N; ++i)
		if (a[i] == X)
			ans = std::min(compute(N, X, i+1), ans); 

	pnl(ans);
}