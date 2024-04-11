#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef double db;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, w, ans, conn, rev[1005], rev2[1005], sumW[1005], sumB[1005], link[1005], sz[1005], W[1005], B[1005], mem[1005][1005];
bool V[1005];
vector<ii> total[1005];

int dp(int n, int w) {
	if (n == 0) return (w < 0 ? -1e17 : 0);
	if (w < 0) return -1e17;
	if (mem[n][w] != -1) return mem[n][w];
	int res = dp(n - 1, w);
	for (auto j : total[n])
		res = max(res, dp(n - 1, w - j.first) + j.second);
	res = max(res, dp(n - 1, w - sumW[rev2[n]]) + sumB[rev2[n]]);
	return mem[n][w] = res;
}

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	sumW[a] += sumW[b];
	sumB[a] += sumB[b];
	link[b] = a;
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> w;
	for (int i = 1; i <= N; i++) cin >> W[i], link[i] = i, sz[i] = 1, sumW[i] = W[i];
	for (int i = 1; i <= N; i++) cin >> B[i], sumB[i] = B[i];
	for (int x, y; M--; ) {
		cin >> x >> y;
		unite(x, y);
	}
	for (int i = 1; i <= N; i++)
		if (W[i] <= w) ans = max(ans, B[i]);
	for (int i = 1; i <= N; i++) {
		if (!V[find(i)]) {
			V[find(i)] = 1;
			rev[find(i)] = ++conn;
			rev2[conn] = find(i);
		}
		total[rev[find(i)]].eb(W[i], B[i]);
	}
	cout << dp(conn, w) << '\n';
}