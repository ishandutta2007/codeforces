#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	vector< vector<int> > adj(n); for (int o = 0; o < n - 1; o++) { int x, y; cin >> x >> y; x--; y--; adj[x].pb(y); adj[y].pb(x); }
	for (int i = 0; i < n; ++i) {
		if (adj[i].size() == 2) {
			cout << "NO" << '\n';
			exit(0);
		}
	}
	cout << "YES" << '\n';
}