#include<bits/stdc++.h>
#define N 114514
#define ll long long
using namespace std;
int n, m;
ll ans, a[N];
void xg(int x, int y) {
	if(x > n) return;
	if(x == 1) return (void)(ans += y, a[1] += y);
	ans -= max(a[x], 0ll), a[x] += y, ans += max(a[x], 0ll);
}
ll xsqz() {
	return (ans + 20000000000000001) / 2 - 10000000000000000;
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for(int i = n; i >= 1; i--) a[i] -= a[i - 1];
	for(int i = 2; i <= n; i++) ans += max(a[i], 0ll);
	ans += a[1];
	printf("%lld\n", xsqz());
	scanf("%d", &m);
	while(m--) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		xg(l, x), xg(r + 1, -x);
		printf("%lld\n", xsqz());
	}
	return (0 - 0);
}