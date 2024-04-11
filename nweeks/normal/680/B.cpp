#include <bits/stdc++.h>

int		main(void)
{
	int		N, pos;

	std::cin >> N >> pos;
	--pos;
	std::vector<int> crim(N);

	for (int i(0); i < N; ++i)
		std::cin >> crim[i];

	int		count(crim[pos]);
	for (int i(1); i < N; ++i)
	{
		if (pos - i < 0 and pos + i >= N)
			break;
		else if (pos - i < 0)
			count += crim[pos + i];
		else if (pos + i >= N)
			count += crim[pos - i];
		else if (crim[pos + i] and crim[pos - i])
			count += 2;
	}
	

	std::cout << count << std::endl;
}