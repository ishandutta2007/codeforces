#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
#include <assert.h>
using namespace std;
const int N = 200000;
const int mod = 1000000007;
#define mul(x,y) (long long)(x)*(y)%mod
int a[N];
int par[N];
int vis[N];
int cyc[N];
int find(int i) {
	while (par[i] >= 0) i = par[i];
	return i;
}
void merge(int i, int j) {
	i = find(i); j = find(j); if (i == j)return;
	if (par[i] < par[j]) swap(i, j);
	par[j] += par[i]; par[i] = j;
}
void dfs(int i) {
	if (vis[a[i]] > 0) {
		cyc[find(i)] = vis[i] - vis[a[i]] + 1;
	}
	else if(!vis[a[i]]){
		vis[a[i]] = vis[i] + 1;
		dfs(a[i]);
	}
	vis[i] = -1;
}
int mpow(int n, int e) {
	if (!e) return 1;
	int t = mpow(n, e / 2);
	t = mul(t, t);
	if (e & 1) t = mul(t, n);
	return t;
}
int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) par[i] = -1;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x); a[i] = x - 1;
		merge(i, a[i]);
	}
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);
	int ans = 1;
	for (int i = 0; i < n; i++) {
		int f = find(i);
		if (vis[f]) {
			int C = -par[f];
			int cy = cyc[f];
			C -= cy;
			ans = mul(ans, mpow(2, C));
			ans = mul(ans, mpow(2, cy) - 2);
			if (ans < 0) ans += mod;
			vis[f] = 0;
		}
	}
	printf("%d\n", ans);
}