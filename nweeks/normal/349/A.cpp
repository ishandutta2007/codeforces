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
	int		n;
	std::cin>>n;

	int		fif(0), hund(0), twen(0);

	while (n--)
	{
		int	a;
		std::cin>>a;
		if (a == 25)
			twen++;
		else if (a == 50)
		{
			if (twen >= 1)
				twen--, fif++;
			else
			{
				pnl("NO");
				return 0;
			}
		}
		else
		{
			if (fif and twen)
				--fif, --twen, ++hund;
			else if (twen >= 3)
				twen -= 3, hund++;
			else
			{
				pnl("NO");
				return 0;
			}
		}
	}
	pnl("YES");
}