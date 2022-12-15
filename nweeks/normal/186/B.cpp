#include <bits/stdc++.h>

struct P
{
	double a;
	int	i;

	bool	operator<(P other) const 
	{return a > other.a or (a == other.a and i < other.i);}
};

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int		n,t1,t2,k;
	std::cin>>n>>t1>>t2>>k;

	std::vector<P>	a(n);
	for (int i(0); i < n; ++i)
	{
		int		ai, bi;
		std::cin>>ai>>bi;
		a[i].a = std::max(ai*t1*(1-k/100.0) + bi*t2,bi*t1*(1-k/100.0)+ai*t2);
		a[i].i = i+1;
	}
	std::sort(a.begin(), a.end());
	std::cout.precision(2);
	for (auto v : a)
		std::cout << std::fixed << v.i << " " << v.a << "\n";
}