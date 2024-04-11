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

int N, M, K, x, mem[500005][25];
vector<ii> adj[500005];

int conv(int r, int c) {
	return (r - 1) * M + c;
}

int dp(int x, int k) {
	if (k == 0) return 0;
	if (k & 1) return 1e16;
	if (mem[x][k] != -1) return mem[x][k];
	int ret = 1e16;
	for (auto u : adj[x])
		ret = min(ret, dp(u.first, k - 2) + u.second * 2);
	return mem[x][k] = ret;
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j < M; j++) {
			cin >> x;
			adj[conv(i, j)].eb(conv(i, j + 1), x);
			adj[conv(i, j + 1)].eb(conv(i, j), x);
		}
	for (int i = 1; i < N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> x;
			adj[conv(i, j)].eb(conv(i + 1, j), x);
			adj[conv(i + 1, j)].eb(conv(i, j), x);
		}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int tmp = dp(conv(i, j), K);
			if (tmp == 1e16) cout << -1;
			else cout << tmp;
			cout << ' ';
		}
		cout << '\n';
	}
}