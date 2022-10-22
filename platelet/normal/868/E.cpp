#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)

using namespace std;
const int N = 55, Inf = 1e9;
int n, s, m, ev[N * 2], ew[N * 2], cnt[N], deg[N];
vector <int> G[N];
int f[N][N * 2][N];
void solve(int, int);
int dp(int i, int j, int k) {
	if(!f[i][j][k]) solve(i, j);
	return f[i][j][k];
}
struct node {
	int i, e, c;
	int val()const { return c < i ? dp(i, e, c + 1) : 0; }
	bool operator <(const node& b)const { return val() < b.val(); }
};
void solve(int i, int j) {
	f[i][j][0] = Inf;
	if(deg[ev[j]] == 1)
		rep(k, 1, i) f[i][j][k] = k < i ? dp(i - k, j ^ 1, i - k) + ew[j] : ew[j];
	else {
		priority_queue <node> q;
		for(int e : G[ev[j]]) if(e ^ j ^ 1) q.push({ i, e, 0 });
		rep(k, 1, i) {
			node x = q.top(); q.pop();
			f[i][j][k] = min(f[i][j][k - 1], x.val() + ew[j]);
			x.c++, q.push(x);
		}
	}
}
int dfs(int u, int fa) {
	int res = cnt[u];
	for(int e : G[u]) if(ev[e] ^ fa) res += dfs(ev[e], u);
	return res;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	int u, v, w;
	rep(i, 2, n) {
		int a = i * 2, b = a + 1;
		cin >> u >> v >> w, deg[ev[a] = v]++, deg[ev[b] = u]++, ew[a] = ew[b] = w;
		G[u].push_back(a), G[v].push_back(b);
	}
	cin >> s >> m;
	rep(i, 1, m) cin >> u, cnt[u]++;
	int ans = Inf;
	for(int e : G[s]) ans = min(ans, dp(m, e, dfs(ev[e], s)));
	cout << ans;
	return 0;
}