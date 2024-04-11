#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

int N, M, X[505];
long double R = 0;
vector<pair<int, int> > adj[505];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> X[i];
	for (int u, v, w; M--; ) {
		cin >> u >> v >> w;
		adj[u].eb(v, w);
		adj[v].eb(u, w);
	}
	for (int i = 1; i <= N; i++)
		for (auto u : adj[i])
			R = max(R, (ld(X[i]) + ld(X[u.first])) / ld(u.second));
	cout << fixed << setprecision(10) << R << '\n';
}