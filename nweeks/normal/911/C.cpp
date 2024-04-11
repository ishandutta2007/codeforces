#include <bits/stdc++.h>

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
	int	a[3];
	for (int i(0); i < 3; ++i)
		std::cin>>a[i];
	std::sort(a,a+3);

	if (a[0] == 1 or (a[0] == 2 and a[1] == 2) or (a[0] == 3 and a[1] == 3 and a[2] == 3) or (a[0] == 2 and a[1] == 4 and a[2] == 4))
		pnl("YES");
	else
		pnl("NO");
}