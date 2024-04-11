#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define upd(a, b) (a = max(a, b))

using namespace std;
const int N = 2e5 + 5, K = 2e5;
int n, eid, co[N * 3];
vector <pair <int, int>> G[N * 2];
void dfs(int u) {
	while(!G[u].empty()) {
		auto [v, id] = G[u].back(); G[u].pop_back();
		if(!co[abs(id)]) co[abs(id)] = 1 + (id > 0), dfs(v);
	}
}
void add(int u, int v) {
	G[u].push_back({ v, ++eid });
	G[v].push_back({ u, -eid });
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n;
	int x, y;
	rep(i, 1, n) scanf("%d%d", &x, &y), add(x, y + K);
	rep(i, 1, K * 2) if(G[i].size() & 1) add(K * 2 + 1, i);
	rep(i, 1, K * 2) dfs(i);
	rep(i, 1, n) putchar(co[i] == 1 ? 'r' : 'b');
	return 0;
}