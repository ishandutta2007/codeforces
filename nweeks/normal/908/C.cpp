#include <bits/stdc++.h>

int	R;

struct Disque
{
	double	x, y;
	
	bool	intersects(Disque other)
	{
		return (2 * R>= fabs(other.x - x));
	}
};

const int	MAX = 1001;

double	end[MAX];
Disque	disques[MAX];

int		main(void)
{
	int	N;
	std::cin >> N >> R;

	for (int i(0); i < N; ++i)
		std::cin >> disques[i].x;

	disques[0].y = R;
	

	for (int i(1); i < N; ++i)
	{
		disques[i].y = R;
		for (int j(0); j < i; ++j)
		{
			if (disques[i].intersects(disques[j]))
				disques[i].y = std::max(disques[i].y, sqrt(4 * R * R - (disques[i].x - disques[j].x) * (disques[i].x - disques[j].x)) + disques[j].y);
		}
	}
	std::cout.precision(7);
	for (int i(0); i < N; ++i)
		std::cout << std::fixed << disques[i].y << " ";
	std::cout << std::endl;
}