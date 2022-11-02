#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int a, b, c; cin >> a >> b >> c;
		if (a > b) swap(a, b);
		if (b > c) swap(b, c);
		if (a > b) swap(a, b);
		assert(a <= b && b <= c);
		int ans = b - a;
		c -= b - a, b -= b - a;
		int l = 0, r = 100000000;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			int na = a - (mid + 1) / 2, nb = b - mid / 2, nc = c - mid;
			if (na < 0 || nb < 0 || nc < nb || nc < 0) r = mid - 1;
			else l = mid;
		}
		ans += l;
		a = a - (l + 1) / 2, b = b - l / 2, c = c - l;
		if (a != b && b) b--, c--, ans++;
		if (a == b && b == c && a && b) ans += (a + b + c) >> 1;
		printf("%d\n", ans);
	}
	return 0;
}