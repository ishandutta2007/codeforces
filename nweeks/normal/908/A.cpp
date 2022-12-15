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

bool	in(char find, std::string s)
{
	for (auto c  : s)
		if (find == c) return true;
	return false;
}

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	std::string s;

	std::string vowel = "aeiou";
	std::string odd = "13579";

	int	ans(0);
	std::cin >> s;
	for (auto c : s)
		if (in(c,vowel) or in(c,odd)) ++ ans;
	pnl(ans);
}