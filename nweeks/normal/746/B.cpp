#include <bits/stdc++.h>

int			main(void)
{
	int		size;
	std::cin >> size;

	std::string s;
	std::string result = "";

	std::cin >> s;

	if (size % 2 == 1)
	{
		for (int i(0); i < size; ++i)
		{
			if (i % 2 == 0)
				result += s[i];
			else
				result = s[i] + result;
		}
	}
	else
	{
		result += s[0];

		for (int i(1); i < size; ++i)
		{
			if (i % 2 == 1)
				result += s[i];
			else
				result = s[i] + result;
		}
	}
	std::cout << result << std::endl;
}