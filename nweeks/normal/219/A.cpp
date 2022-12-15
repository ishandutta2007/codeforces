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
	int		k;
	std::string s;
	std::cin >> k >> s;

	int		occur[26] = {};
	for (auto c : s)
		occur[c - 'a']++;
	for (int i(0); i < 26; ++i)
		if (occur[i] % k != 0)
		{
			pnl(-1);
			return 0;
		}
	for (int l(0); l < k;++l)
		for (int i(0); i < 26; ++i)
			for (int j(0); j < occur[i]/k;++j)
				std::cout<<(char)(i+'a');
	std::cout<<std::endl;
}