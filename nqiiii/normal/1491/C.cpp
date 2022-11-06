#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5;
int T, n, u, v;
int s[maxn + 10], d[maxn + 10];


int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) d[i] = 0;
		for (int i = 1; i <= n; ++i) scanf("%d", &s[i]);
		for (int i = 1; i <= n; ++i)  {
			++d[i + 2];
			--d[min(i + s[i], n) + 1];
		}
		for (int i = 1; i <= n; ++i) d[i] += d[i - 1];
		ll ans = 0, v = 0;
		for (int i = n; i >= 1; --i) {
			ans += s[i] - d[i] - 1;
			if (ans < 0) ans = 0;
		}
		printf("%lld\n", ans);
	}
}