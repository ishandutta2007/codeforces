#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define upd(a, b) (a = min(a, b))

using namespace std;
const int N = 1 << 18;
typedef long long ll;
int n, a[N], fa[N], sz[N], vis[N];
vector <int> nds[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	ll as = 0;
	rep(i, 1, n) {
		scanf("%d", &a[i]), as -= a[i];
		nds[a[i]].push_back(i);
	}
	nds[0].push_back(0);
	rep(i, 0, n) fa[i] = i, sz[i] = 1;
	per(S, N - 1, 1) for(int T = S; T > S / 2; --T &= S) {
		if(nds[T].empty() || nds[S ^ T].empty()) continue;
		auto mrg = [&](int u, int v) {
			u = find(u), v = find(v);
			if(u == v) return;
			if(sz[u] < sz[v]) swap(u, v);
			fa[v] = u, sz[u] += sz[v];
			as += S;
			if(sz[u] == n + 1) cout << as, exit(0);
		};
		mrg(nds[T][0], nds[S ^ T][0]);
		if(!vis[T]) for(int u : nds[T]) mrg(u, nds[S ^ T][0]);
		if(!vis[S ^ T]) for(int v : nds[S ^ T]) mrg(nds[T][0], v);
		vis[T] = vis[S ^ T] = 1;
	}
	puts("0");
	return 0;
}