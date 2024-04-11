#include <bits/stdc++.h>

bool	check(int a, int b, bool pair, int next)
{
	if (a == b and b == next)
		return false;
	if (pair and b == next)
		return false;
	return true;
}

int		main(void)
{
	std::string s, result;
	std::cin >> s;

	int		a(-1), b(-2);
	bool	pair = false;

	for (auto c : s)
		if (check(a, b, pair, c - 'a'))
		{
			pair = (a == b);
			a = b;
			b = c - 'a';
			result += c;
		}
	std::cout << result << std::endl;
}