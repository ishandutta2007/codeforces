#include <bits/stdc++.h>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		long long a, b;
		std::cin >> a >> b;
		std::cout << a * (long long)(log10(b + 1)) << std::endl;
	}
}