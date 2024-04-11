#include<bits/stdc++.h>

typedef long long ll;
const ll maxn = 200005;
ll n, m, a[maxn], cnt;
int main() {
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	for (int i = 1; i <= n; i++) {
		cnt += a[i]; 
		printf("%lld ", cnt / m);
		cnt %= m; 
	}
	return 0;
}