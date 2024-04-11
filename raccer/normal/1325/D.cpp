#include <bits/stdc++.h>
using namespace std;
int main () {
	long long a, b; cin >> a >> b;
	if (a % 2 != b % 2 || a > b) {
		printf("-1\n");
		return 0;
	}
	if (a == 0 && b == 0) {
		printf("0\n");
		return 0;
	}
	if (a == b) {
		printf("1\n%I64d\n", a);
		return 0;
	}
	long long x = b - a >> 1, y = b - a >> 1;
	x += a;
	if ((x ^ y) == a) {
		printf("2\n%I64d %I64d\n", x, y);
		return 0;
	}
	printf("3\n%I64d %I64d %I64d\n", a, y, y);
	return 0;
}