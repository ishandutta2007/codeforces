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

int N, M, ans, curr, sz[100005], dep[100005], down[100005], inv[100005], pt[100005], up[100005];
bool vis[100005];
map<int, int> cntDown, cntUp;
vector<ii> downPath, upPath, adj[100005];

int ex_euclid(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1, d = ex_euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int dfs(int n, int e = -1) {
	sz[n] = 1;
	for (auto u : adj[n])
		if (u.first != e && !vis[u.first])
			sz[n] += dfs(u.first, n);
	return sz[n];
}

int cent(int n, int s, int e = -1) {
	for (auto u : adj[n])
		if (u.first != e && !vis[u.first] && sz[u.first] > (s >> 1))
			return cent(u.first, s, n);
	return n;
}

void getPaths(int n, int e = -1) {
	downPath.eb(down[n], n);
	upPath.eb(up[n], n);
	for (auto u : adj[n])
		if (u.first != e && !vis[u.first]) {
			dep[u.first] = dep[n] + 1;
			up[u.first] = (up[n] + pt[dep[n]] * u.second) % M;
			down[u.first] = (down[n] * 10 + u.second) % M;
			getPaths(u.first, n);
		}
}

void build(int n) {
	int s = dfs(n), c = cent(n, s);
	dep[n] = down[n] = up[n] = 0;
	cntUp.clear();
	cntDown.clear();
	cntUp[0]++;
	cntDown[0]++;
	vis[c] = 1;
	curr = c;
	//cout << "CENT " << c << '\n';
	for (auto u : adj[c])
		if (!vis[u.first]) {
			downPath.clear();
			upPath.clear();
			dep[u.first] = 1;
			up[u.first] = down[u.first] = u.second % M;
			getPaths(u.first);
			for (auto i : downPath) {
				//cout << "DOWN " << i.second << " NEED " << (-i.first % M * inv[dep[i.second]] % M + M) % M << '\n';
				ans += cntUp[(-i.first % M * inv[dep[i.second]] % M + M) % M];
				//cout << "RET " << cntUp[(-i.first % M * inv[dep[i.second]] % M + M) % M] << '\n';
			}
			for (auto i : upPath) {
				//cout << "UP " << i.second << " NEED " << i.first << '\n';
				ans += cntDown[i.first];
				//cout << "RET " << cntDown[i.first] << '\n';
			}
			for (auto i : downPath)
				cntDown[(-i.first % M * inv[dep[i.second]] % M + M) % M]++;
			for (auto i : upPath)
				cntUp[i.first]++;
		}
	for (auto u : adj[c])
		if (!vis[u.first]) build(u.first);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	if (M == 1) return cout << N * N - N << '\n', 0;
	pt[0] = inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		pt[i] = pt[i - 1] * 10 % M;
		int x, y, g = ex_euclid(pt[i], M, x, y);
		assert(g == 1);
		inv[i] = (x % M + M) % M;
	}
	for (int i = 1, u, v, w; i < N; i++) {
		cin >> u >> v >> w;
		adj[u].eb(v, w);
		adj[v].eb(u, w);
	}
	build(0);
	cout << ans << '\n';
}