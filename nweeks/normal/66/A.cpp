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

	std::string biginteger = "9223372036854775807";
	std::string l = "2147483647";
	std::string i = "32767";
	std::string sh = "127";

	if (s.size() > biginteger.size() or (s > biginteger and s.size() == biginteger.size() ))
		pnl("BigInteger");
	else if (s.size() > l.size() or (s > l and s.size() == l.size()))
		pnl("long");
	else if (s.size() > i.size() or (s > i and s.size() == i.size()))
		pnl("int");
	else if (s.size() > sh.size() or (s > sh and s.size() == sh.size()))
		pnl("short");
	else
		pnl("byte");

}