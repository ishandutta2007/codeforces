#include <bits/stdc++.h>

const int	NB_D = 4;
const int	DY[] = {-1, 1, 0, 0};
const int	DX[] = {0, 0, -1, 1};

int		main(void)
{
	std::ios_base::sync_with_stdio(false);
	int		p, q, l, r;
	std::cin >> p >> q >> l >> r;
	std::vector<int>	a(p);
	std::vector<int>	b(p);
	std::vector<int>	c(q);
	std::vector<int>	d(q);

	for (int i(0); i < p; ++i)
		std::cin >> a[i] >> b[i];
	for (int i(0); i < q; ++i)
		std::cin >> c[i] >> d[i];

	int		cnt(0);

	for (int start(l); start <= r; ++start)
	{
		bool	found = false;
		for (int i(0); i < p and !found; ++i)
			for (int j(0); j < q and !found; ++j)
				if (!(a[i] > d[j] + start or b[i] < c[j] + start 
							or
							c[j] + start > b[i] or d[j] + start < a[i]))
					found = true;
		cnt += found;
	}
	std::cout << cnt << std::endl;
}