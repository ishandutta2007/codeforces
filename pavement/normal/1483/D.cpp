#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ppb pop_back
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, Q, ans, act[605], mat[605][605], dist[605], u[400005], v[400005], w[400005];
bool useful[400005];
vector<ii> adj[605], vec[605];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (i != j) mat[i][j] = 1e16;
	for (int i = 1; i <= M; i++) {
		cin >> u[i] >> v[i] >> w[i];
		mat[u[i]][v[i]] = mat[v[i]][u[i]] = min(mat[u[i]][v[i]], w[i]);
		adj[u[i]].eb(v[i], w[i]);
		adj[v[i]].eb(u[i], w[i]);
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
	cin >> Q;
	for (int i = 1, a, b, l; i <= Q; i++) {
		cin >> a >> b >> l;
		vec[a].eb(b, l);
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) dist[j] = 1e16;
		for (auto j : vec[i])
			dist[j.first] = min(dist[j.first], -j.second);
		for (int j = 1; j <= N; j++) {
			act[j] = 1e16;
			for (int k = 1; k <= N; k++)
				act[j] = min(act[j], mat[j][k] + dist[k]);
		}
		for (int j = 1; j <= M; j++)
			if (act[v[j]] <= -mat[i][u[j]] - w[j] || act[u[j]] <= -mat[i][v[j]] - w[j]) useful[j] = 1;
		// dist(v[j], b) - l <= - dist(a, u[j]) - w
	}
	for (int i = 1; i <= M; i++) ans += useful[i];
	cout << ans << '\n';
}