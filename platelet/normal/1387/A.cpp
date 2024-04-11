#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 1e5 + 5;
int n, m, tag, x, k[N], b[N], as[N];
vector <pair <int, int>> G[N];
vector <int> cc;
void dfs(int u) {
	cc.pb(u);
	for(auto [v, w] : G[u]) {
		if(!k[v]) k[v] = -k[u], b[v] = w - b[u], dfs(v);
		else if(k[u] == k[v]) {
			if(!tag) x = (w - b[u] - b[v]) / (k[u] + k[v]), tag = 1;
			else if((k[u] + k[v]) * x + b[u] + b[v] != w) tag = -1;
		} else if(b[u] + b[v] != w) tag = -1;
		if(!~tag) return;
	}
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	int u, v, w;
	rep(i, 1, m) {
		scanf("%d%d%d", &u, &v, &w), w *= 2;
		G[u].pb({v, w}), G[v].pb({u, w});
	}
	rep(i, 1, n) if(!k[i]) {
		k[i] = 1, tag = 0, cc.clear(), dfs(i);
		if(tag == -1) puts("NO"), exit(0);
		else {
			if(!tag) {
				vector <int> t;
				for(int u : cc) t.pb(-b[u] / k[u]);
				nth_element(t.begin(), t.begin() + t.size() / 2, t.end());
				x = t[t.size() / 2];
			}
			for(int u : cc) as[u] = k[u] * x + b[u];
		}
	}
	puts("YES");
	rep(i, 1, n) printf("%.1lf ", as[i] / 2.0);
	return 0;
}