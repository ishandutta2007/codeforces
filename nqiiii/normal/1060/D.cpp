#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000;
int n, l[maxn + 10], r[maxn + 10];;
ll ans;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &l[i], &r[i]);
	sort(l + 1, l + n + 1); sort(r + 1, r + n + 1);
	for (int i = 1; i <= n; ++i) ans += max(l[i], r[i]);
	printf("%lld", ans + n);
}