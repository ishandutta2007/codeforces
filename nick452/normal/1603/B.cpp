#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int solve(int x, int y) {
	if (x == y) {
		return x;
	}
	if (x > y) {
		return x + y;
	}
	return y - y % x / 2;
}

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int t;
	for (cin >> t; t > 0; --t) {
		int x, y;
		cin >> x >> y;
		int n = solve(x, y);
		assert(n % x == y % n);
		printf("%d\n", n);
	}
	return 0;
}