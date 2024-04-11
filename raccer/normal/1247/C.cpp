#include <bits/stdc++.h>
using namespace std;

int count(long long x) {
	int cnt = 0;
	while (x) {
		x -= x & -x;
		cnt++;
	}
	return cnt;
}

int main () {
	int n, p; cin >> n >> p;
	int ans = -1;
	for (int i = 1; i <= 1000000; i++) {
		long long x = n - 1ll * p * i;
		if (x < 0) break;
		if (x >= i && count(x) <= i) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}