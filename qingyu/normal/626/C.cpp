#include <bits/stdc++.h>
int main()
{
	int n, m; scanf("%d%d", &n, &m); int a = std::max(2 * n, 3 * m);
	while (a / 2 + a / 3 - a / 6 < n + m) ++a;
	printf("%d", a);
}