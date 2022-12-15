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
	int	N, K;
	std::cin >> N >> K;

	vi	val;
	
	int	cur_rating(0);
	int	max_improve(0);

	for (int i(0); i < N; ++i)
	{
		int a; std::cin >> a;

		cur_rating += a/10;
		max_improve += 10 - (std::ceil(a/10.0));

		a = 10 - a%10;
		if (a!=10 and a)
			val.pb(a);
	}

	std::sort(all(val));

	for (int i(0); i < val.size(); ++i)
	{
		if (val[i] > K)
			break ;
		++cur_rating;
		K -= val[i];
	}
	K /= 10;
	cur_rating += std::min(K, max_improve);
	pnl(cur_rating);
}