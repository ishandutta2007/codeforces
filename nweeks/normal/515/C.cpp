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
	int	n;
	std::string s;
	std::cin >> n >> s;

	int	two(0), three(0), five(0), seven(0);

	for (auto c : s)
		for (int i = c - '0'; i > 1; --i)
		{
			int	k = i;
			while (k % 2 == 0)
				two++, k /= 2;
			while (k % 3 == 0)
				three++, k/=3;
			while (k % 5 == 0)
				five++, k /= 5;
			while (k % 7 == 0)
				seven++, k /= 7;
		}
	while (seven > 0)
	{
		std::cout << 7;
		seven--;
		five--;
		two -= 4;
		three -= 2;
	}
	while (five > 0)
	{
		std::cout << 5;
		--five;
		two -= 3;
		three--;
	}
	while (three > 0)
	{
		std::cout << 3;
		--three;
		--two;
	}
	while (two-- > 0)
		std::cout << 2;
	std::cout<<std::endl;
}