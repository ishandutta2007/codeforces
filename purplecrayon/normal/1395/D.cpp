#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;
 
int n, d, m, k;
ll ans, a[N];
int main() {
	scanf("%d%d%d", &n, &d, &m);
	for(int i = 1; i <= n; ++i)
		scanf("%lld", a + i);
	sort(a + 1, a + 1 + n);
	for(int i = 1; i <= n; ++i) {
		if(a[i] <= m)
			++k;
		a[i] += a[i - 1];
	}
	ans = a[k];
	for(int i = n, j = 1; i >= 1 && j <= n - k; i -= d + 1, ++j)
		ans = max(ans, a[k] - a[max(0, k - (i - 1))] + a[n] - a[n - j]);
	printf("%lld\n", ans);
	return 0;
}