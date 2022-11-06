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
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

int N, M, Q, U[100005], V[100005], W[100005], link[65][100005], sz[65][100005];
bool has[65][100005];

int find(int x, int k) {
	if (link[k][x] == x) return x;
	return link[k][x] = find(link[k][x], k);
}

void unite(int a, int b, int k) {
	a = find(a, k);
	b = find(b, k);
	if (a == b) return;
	if (sz[k][b] > sz[k][a]) swap(a, b);
	sz[k][b] += sz[k][a];
	has[k][a] |= has[k][b];
	link[k][b] = link[k][a];
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++)
		cin >> U[i] >> V[i] >> W[i];
	for (int k = 0; k < 60; k++) {
		for (int i = 1; i <= N; i++) {
			link[k][i] = i;
			sz[k][i] = 1;
		}
	}
	for (int k = 0; k < 30; k++) {
		for (int i = 1; i <= M; i++)
			if (W[i] & (1 << k)) unite(U[i], V[i], k);
		
	}
	for (int k = 1; k < 30; k++) {
		for (int i = 1; i <= M; i++)
			if ((W[i] & 1) && (W[i] & (1 << k)))
				unite(U[i], V[i], k + 30);
			else if ((W[i] & 1) ^ 1) {
				unite(U[i], V[i], k + 30);
				has[k + 30][find(U[i], k + 30)] = 1;
			}
	}
	cin >> Q;
	for (int u, v; Q--; ) {
		cin >> u >> v;
		int ans = 2;
		for (int k = 0; k < 30; k++)
			if (find(u, k) == find(v, k)) ans = 0;
		for (int k = 1; k < 30; k++)
			if (has[k + 30][find(u, k + 30)]) ans = min(ans, 1ll);
		cout << ans << '\n';
	}
}