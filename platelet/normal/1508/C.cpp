#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
const int N = 2e5 + 5;
typedef long long ll;
int n, m, fa[N], xorsu, eid, tid;
int find(int x) { return x ^ fa[x] ? fa[x] = find(fa[x]) : x; }
int mrg(int u, int v) {
	if((u = find(u)) ^ (v = find(v))) return fa[u] = v;
	return 0;
}
vector <int> G[N];
struct edge {
	int u, v, w;
	bool operator <(const edge& b)const {
		return w < b.w;
	}
} e[N], t[N];
set <int> s;
void dfs(int u) {
	s.erase(u);
	For(i, 0, G[u].size() - 1) {
		int v = G[u][i], nxt = G[u][i + 1];
		while(!s.empty() && *s.rbegin() > v) {
			int vv = *s.upper_bound(v);
			if(vv >= nxt) break;
			t[++tid] = {u, vv}, dfs(vv);
		}
	}
}
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	rep(i, 1, m) {
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w), xorsu ^= e[i].w;
		G[e[i].u].pb(e[i].v), G[e[i].v].pb(e[i].u);
	}
	rep(i, 1, n) G[i].pb(0), G[i].pb(n + 1), sort(G[i].begin(), G[i].end()), s.insert(i);
	while(!s.empty()) dfs(*s.begin());
	sort(e + 1, e + m + 1);
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, m) if(mrg(e[i].u, e[i].v)) e[++eid] = e[i];
	if(tid < n * (n - 1ll) / 2 - m) {
		rep(i, 1, n) fa[i] = i;
		rep(i, 1, tid) mrg(t[i].u, t[i].v);
		ll as = 0;
		rep(i, 1, eid) if(mrg(e[i].u, e[i].v)) as += e[i].w;
		cout << as;
	} else {
		ll as = 1e18;
		rep(i, 0, tid) {
			rep(j, 1, n) fa[j] = j;
			rep(j, 1, tid) if(j ^ i) mrg(t[j].u, t[j].v);
			ll su = i ? 0 : xorsu;
			rep(j, 1, eid) if(mrg(e[j].u, e[j].v)) su += e[j].w;
			as = min(as, su);
		}
		cout << as;
	}
	return 0;
}