#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
map<int, char> e[MAXN];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n, m; cin >> n >> m;
	int pr = 0, pc = 0;
	while (m--) {
		char t; cin >> t;
		if (t == '+') {
			int u, v; char c; cin >> u >> v >> c;
			// u->v
			if (e[v][u]) {
				pr++;
				if (e[v][u] == c) {
					pc++;
				}
			}
			e[u][v] = c;
		} else if (t == '-') {
			int u, v; cin >> u >> v;
			if (e[u][v] && e[v][u]) {
				pr--;
				if (e[u][v] == e[v][u]) {
					pc--;
				}
			}
			e[u][v] = 0;
		} else {
			int k; cin >> k;
			if (k % 2) {
				if (pr) cout << "YES\n"; else cout << "NO\n";
			} else {
				if (pc) cout << "YES\n"; else cout << "NO\n";
			}
		}
	}

	return 0;
}