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

const int	MAXN = 1e5;
int			A[MAXN], B[MAXN];

struct Itema
{
	int		index, val;

	bool	operator<(Itema other) const
	{
		return val > other.val;
	}
};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int	N;
	std::cin >> N;
	
	std::vector<Itema>	a(N);


	for (int i(0); i < N; ++i)
	{
		std::cin >> A[i];
		a[i] = {i, A[i]};
	}
	FOR(i,0,N)
		std::cin >> B[i];

	std::sort(all(a));

	pnl(N / 2 + 1);
	std::cout << a[0].index+1 << " ";
	for (int i(0); i < N / 2; ++i)
	{
		if (2*i+2 >= N or (B[a[2*i+1].index] >= B[a[2*i+2].index]))
			std::cout << a[2*i+1].index+1 << " ";
		else
			std::cout << a[2*i+2].index + 1 << " ";
	}
	std::cout << std::endl;
}