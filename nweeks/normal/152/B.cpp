#include <bits/stdc++.h>

struct	Vector
{
	int		dx, dy;
};

int		main(void)
{
	int		n,m,x,y,k;
	std::cin >> m >> n>>x>>y>>k;
	std::vector<Vector>	v(k);

	for (auto&val:v)
		std::cin>>val.dx>>val.dy;
	
	long long cnt(0);

	for (auto vec : v)
	{
		int		steps = 1e9;
		if (vec.dx > 0)
			steps = std::min(steps, (m - x) / vec.dx);
		else if (vec.dx < 0)
			steps = std::min((1-x) / vec.dx, steps);
		if (vec.dy > 0)
			steps = std::min(steps, (n - y) / vec.dy);
		else if (vec.dy < 0)
			steps = std::min(steps, (1-y)/vec.dy);
		cnt += steps;
		x += steps * vec.dx;
		y += steps * vec.dy;
	}
	std::cout<<cnt<<std::endl;
}