#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 2e5 + 5;
int n, m, fa[N], fg[N], ans;
struct Edge {
	int u, v, w;
	bool operator <(const Edge& b)const { return w > b.w; }
} E[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

int main() {
	#ifdef local
		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	rep(i, 1, m) scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);
	rep(i, 1, n) fa[i] = i;
	sort(E + 1, E + m + 1);
	rep(i, 1, m) {
		int u = find(E[i].u), v = find(E[i].v), w = E[i].w;
		if(u ^ v && (!fg[u] || !fg[v])) fa[u] = v, fg[v] |= fg[u], ans += w;
		if(u == v && !fg[u]) fg[u] = 1, ans += w;
	}
	return cout << ans, 0;
}