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
	std::cin >> s;

	std::list<int>	rocks;

	std::list<int>::iterator it;
	rocks.push_back(0);
	it = rocks.begin();

	for (int i(0); i < s.size() - 1; ++i)
		if (s[i] == 'l')
			it = rocks.insert(it, i + 1);	
		else
		{
			if (it == rocks.end())
				rocks.push_back(i + 1), it++;
			else
				++it, it = rocks.insert(it, i + 1);
		}
	for (auto v : rocks)
		pnl(v + 1);
}