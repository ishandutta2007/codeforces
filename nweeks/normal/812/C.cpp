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

const int	MAX = 1e5;
const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

ll			arr[MAX];
ll			N, S, cost;

bool	can(int k)
{
	ll	y[N];

	for (int i(0); i < N;++i)
		y[i] = arr[i] + (ll)(i + 1) * k;
	std::sort(y, y + N);
	ll summ(0);
	for (int i(0); i < k; ++i)
	{
		summ += y[i];
		if (summ > S)
			return false;
	}
	cost = summ;
	return true;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::cin >> N >> S;

	for (int i(0); i < N; ++i)
		std::cin >> arr[i];
	int		left(0);
	int		right(N + 1);

	while (left < right - 1)
	{
		int		middle = (left + right) / 2;
		if (can(middle))
			left = middle;
		else
			right = middle;
	}
	if (cost > S)
		std::cout << "0, 0\n";
	std::cout << left << " " << cost << std::endl;
}