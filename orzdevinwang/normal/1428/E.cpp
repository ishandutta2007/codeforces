#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define db double
#define mp make_pair
const int N = 1e6 + 7;
int n, k, a[N], cnt[N];
ll ans = 0;
priority_queue< pair<ll, int> > q;
ll js(int x, int y) {
	int b = x / y, g = x % y;
	return 1ll * b * b * (y - g) + 1ll * (b + 1) * (b + 1) * g;
}
int main() {
	scanf("%d%d", &n, &k), k -= n;
	L(i, 1, n) scanf("%d", &a[i]), ans += 1ll * a[i] * a[i], q.push(mp(js(a[i], 1) - js(a[i], 2), i)), cnt[i] = 1;
	while(k) {
		ans -= q.top().first; 
		int u = q.top().second;
		q.pop();
		++cnt[u];
		q.push(mp(js(a[u], cnt[u]) - js(a[u], cnt[u] + 1), u));
		--k;
	}
	printf("%lld\n", ans);
	return 0;
}