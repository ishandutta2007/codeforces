#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2000;
int n, m, sum, a[maxn + 10], b[maxn + 10], ans;
int c[maxn + 10], d[maxn + 10], x;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	for (int i = 1; i <= m; ++i) scanf("%d", &b[i]);
	for (int i = 1; i <= maxn; ++i) c[i] = d[i] = 2e9;
	for (int i = 1; i <= n; ++i) {
		sum = 0;
		for (int j = i; j <= n; ++j) {
			sum += a[j];
			c[j - i + 1] = min(c[j - i + 1], sum);
		}
	}
	for (int i = 1; i <= m; ++i) {
		int sum = 0;
		for (int j = i; j <= m; ++j) {
			sum += b[j];
			d[j - i + 1] = min(d[j - i + 1], sum);
		}
	}
	scanf("%d", &x);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (1ll * c[i] * d[j] <= x) {
				ans = max(ans, i * j);
			}
	printf("%d", ans);
}