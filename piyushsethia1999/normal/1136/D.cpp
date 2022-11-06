#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	int pinv[n];
	int p[n]; for (int o = 0; o < n; o++) { cin >> p[o]; p[o]--; pinv[p[o]] = o;}
	std::vector<set<int>> adj(n);
	std::vector<bool> vv(n, false);
	std::vector<int> siz(n, 0);
	for (int i = 0; i < m; ++i) {
		int u; cin >> u; u--;
		int v; cin >> v; v--;
		u = pinv[u];
		v = pinv[v];
		if (v == (n - 1)) {
			vv[u] = true;
		} else if(v > u) {
			adj[u].insert(v);
			siz[u]++;			
		}
	}
	set<int> bw;
	set<int> nbw;
	int b = 0;
	int nb = 0;
	for (int i = n - 2; i >= 0; --i) {
		if (vv[i]) {
			if (siz[i] >= b) {
				if (b > nb) {
					int z = 0;
					for (int u : nbw) {
						if (adj[i].find(u) == adj[i].end()) {
							z++;
						}
					}
					if (((b + nb) - z - (siz[i])) != 0) {
						bw.insert(i);
						b++;
					} else {
						nbw.insert(i);
						nb++;
					}
				} else {
					int z1 = 0;
					for (int u : bw) {
						if (adj[i].find(u) == adj[i].end()) {
							z1++;
						} 
					}
					if (z1 != 0) {
						bw.insert(i);
						b++;
					} else {
						nbw.insert(i);
						nb++;
					} 
				}
			} else {
				bw.insert(i);
				b++;
			}
		} else {
			bw.insert(i);
			b++;
		}
	}
	cout << nb << "\n";
}