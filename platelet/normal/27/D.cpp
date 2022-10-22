#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)

using namespace std;
const int N = 105;
int n, m, a[N], b[N], co[N];
vector <int> G[N];
int dfs(int u) {
	for(int v : G[u]) if(co[u] == co[v] || (!co[v] && !dfs((co[v] = 3 - co[u], v)))) return 0;
	return 1;
}
int main() {
	#ifdef local
//		freopen(".in", "r", stdin);
	#endif
	cin >> n >> m;
	rep(i, 1, m) {
		scanf("%d%d", &a[i], &b[i]);
		if(a[i] > b[i]) swap(a[i], b[i]); b[i]--;
		auto chk = [](int L, int R, int l, int r) {
			if(L > l) swap(L, l), swap(R, r);
			return L < l && l <= R && R < r;
		};
		rep(j, 1, i - 1) if(chk(a[i], b[i], a[j], b[j]))
			G[i].push_back(j), G[j].push_back(i);
	}
	rep(i, 1, m) if(!co[i] && !dfs((co[i] = 1, i))) puts("Impossible"), exit(0);
	rep(i, 1, m) putchar(co[i] == 1 ? 'i' : 'o');
}