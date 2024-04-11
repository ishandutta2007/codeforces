#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 2e5 + 5;

int n, m, q, as;
set<int> G[N];

int calc(int u) { return G[u].empty() || *G[u].rbegin() < u; }

int main() {
	// for(cin >> T; T--;) solve();
	cin >> n >> m, as = n;
	int t, u, v;
	while(m--) {
		scanf("%d%d", &u, &v), as -= calc(u) + calc(v);
		G[u].insert(v), G[v].insert(u), as += calc(u) + calc(v);
	}
	for(cin >> q; q--;) {
		scanf("%d", &t);
		if(t == 3) { printf("%d\n", as); continue; }
		scanf("%d%d", &u, &v), as -= calc(u) + calc(v);
		if(t == 1) G[u].insert(v), G[v].insert(u);
		else G[u].erase(v), G[v].erase(u);
		as += calc(u) + calc(v);
	}
	return 0;
}