#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j; i <= k; i++)
#define R(i, j, k) for(int i = j; i >= k; i--)
#define ll long long
using namespace std;
const int N = 1e5 + 7;
int n, a[N];
int head[N], edge_id;
struct node {
	int to, next;
} e[N << 1];
void add_edge(int u, int v) {
	++edge_id, e[edge_id].next = head[u], e[edge_id].to = v, head[u] = edge_id;
}
int cnt[N];
ll sum[N], lcm[N];
ll GCD(ll x, ll y) { return y == 0 ? x : GCD(y, x % y); }
void dfs(int x, int fa) {
	lcm[x] = 1; 
	ll minn = 1e13;
	for(int i = head[x]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa) continue;
		++cnt[x];
		dfs(v, x);
		minn = min(minn, sum[v]);
		if(sum[v] == 0) return sum[x] = 0, void();
		if(lcm[x] / GCD(lcm[x], lcm[v]) > 1e13 / lcm[v]) return sum[x] = 0, void();
		lcm[x] = lcm[x] / GCD(lcm[x], lcm[v]) * lcm[v];
		if(lcm[x] > 1e13) return sum[x] = 0, void();
	}
	if(cnt[x] == 0) return lcm[x] = 1, sum[x] = a[x], void();
	sum[x] = (minn / lcm[x]) * lcm[x] * cnt[x];
	lcm[x] *= cnt[x];
	if(lcm[x] > 1e13) return sum[x] = 0, void();
}
int main() {
	ll All = 0;
	scanf("%d", &n);
	L(i, 1, n) scanf("%d", &a[i]), All += a[i];
	L(i, 1, n - 1) {
		int u, v; scanf("%d%d", &u, &v); add_edge(u, v), add_edge(v, u);
	}
	dfs(1, -1);
	printf("%lld\n", All - sum[1]);
	return 0;
}