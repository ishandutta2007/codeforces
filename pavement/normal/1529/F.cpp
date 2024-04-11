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

int N, M, adj[605][605], dist[605];
bool vis[605];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			adj[i][j] = 1e16;
	for (int a, b, c; M--; ) {
		cin >> a >> b >> c;
		adj[a][b] = min(adj[a][b], c);
	}
	for (int i = 0; i < N; i++) { // i is the source vertex
 		for (int j = 0; j < N; j++)
			dist[j] = adj[i][j], vis[j] = 0;
		while (1) {
			ii tmp = mp((int)1e16, -1);
			for (int j = 0; j < N; j++)
				if (!vis[j]) tmp = min(tmp, mp(dist[j], j));
			if (tmp.second == -1) break;
			for (int k = 0; k < N; k++)
				dist[(k + tmp.first) % N] = min(dist[(k + tmp.first) % N], tmp.first + adj[tmp.second][k]);
			dist[(tmp.second + 1) % N] = min(dist[(tmp.second + 1) % N], tmp.first + 1);
			vis[tmp.second] = 1;
		}
		for (int j = 0; j < N; j++) cout << (i == j ? 0 : dist[j]) << ' ';
		cout << '\n';
	}
}