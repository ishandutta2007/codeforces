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
	std::string s;
	std::cin>>s;
	std::string voyel = "aoyeui";
	for (auto& c : s)
		c = tolower(c);
	for (auto c : s)
	{
		bool	skip = false;
		for (auto k : voyel)
			if (k == c)
				skip = true;
		if (!skip)
			std::cout<< "."<<c;
	}
	std::cout<<std::endl;
}