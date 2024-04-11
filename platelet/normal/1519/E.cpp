#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define eb emplace_back

using namespace std;
const int N = 4e5 + 5;
typedef long long ll;
ll K1[N], K2[N];
int n, ord[N], id[N];
vector <pair <int, int>> G[N];
vector <pair <int, int>> as;
int idx, dfn[N], sz[N];
void add(int u, int v, int i) {
	G[u].eb(v, i), G[v].eb(u, i);
}
void dfs(int u, int f) {
	dfn[u] = ++idx;
	int lst = 0;
	auto ins = [&](int x) {
		if(lst) as.eb(lst, x), lst = 0;
		else lst = x;
	};
	for(auto [v, w] : G[u]) if(!dfn[v]) {
		dfs(v, w), sz[u] += sz[v];
		if(~sz[v] & 1) ins(w);
	} else if(dfn[v] > dfn[u]) ins(w);
	else sz[v]++;
	if(lst && f) as.eb(lst, f);
}
int main() {
	cin >> n;
	int a, b, c, d;
	rep(i, 1, n) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		K1[i * 2 - 1] = ll(a + b) * d, K1[i * 2] = (ll)a * d;
		K2[i * 2 - 1] = (ll)b * c, K2[i * 2] = b * ll(c + d);
	}
	n *= 2;
	rep(i, 1, n) {
		ord[i] = i;
		ll g = __gcd(K1[i], K2[i]);
		K1[i] /= g, K2[i] /= g;
	}
	auto cmp = [](int x, int y) {
		return K1[x] ^ K1[y] ? K1[x] < K1[y] : K2[x] < K2[y];
	};
	sort(ord + 1, ord + n + 1, cmp);
	rep(i, 1, n) id[i] = lower_bound(ord + 1, ord + n + 1, i, cmp) - ord;
	rep(i, 1, n / 2) add(id[i * 2 - 1], id[i * 2], i);
	rep(i, 1, n) dfs(i, 0);
	cout << as.size() << endl;
	for(auto [u, v] : as) printf("%d %d\n", u, v);
	return 0;
}