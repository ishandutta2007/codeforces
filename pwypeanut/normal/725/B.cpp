#include <bits/stdc++.h>
using namespace std;

long long n;
char c;

int main() {
	scanf("%lld%c", &n, &c);
	long long val = 0;
	if (n % 4 == 1 || n % 4 == 3) val = (n - 1) / 4 * 2;
	else val = (n - 1) / 4 * 2 + 1;
	long long ans;
	if (val % 2 == 0) ans = (val / 2) * 16;
	else ans = (val / 2) * 16 + 7;
	if (c == 'f') ans += 1;
	else if (c == 'e') ans += 2;
	else if (c == 'd') ans += 3;
	else if (c == 'a') ans += 4;
	else if (c == 'b') ans += 5;
	else ans += 6;
	printf("%lld\n", ans);
}