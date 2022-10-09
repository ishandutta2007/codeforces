#include <bits/stdc++.h>

int main()
{
	long long a[3];
	std::cin >> a[0] >> a[1] >> a[2];
	std::sort(a, a + 3);
	if (a[1] - a[0] & 1) std::cout << a[2];
	else std::cout << a[1];
}