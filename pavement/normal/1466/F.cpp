#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#ifdef WIN_32
#define getchar_unlocked _getchar_nolock
#endif
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
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
typedef long double ld;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, curr, link[500005], sz[500005], fac[500005];
vector<int> ans;
const int MOD = 1e9 + 7;
iii T[500005];

int find(int x) {
	if (x == link[x]) return x;
	return link[x] = find(link[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (sz[b] > sz[a]) swap(a, b);
	sz[a] += sz[b];
	link[b] = a;
}

int exp_mod(int a, int b, int m) {
	a %= m;
	b %= (m - 1);
	int r = 1;
	while (b) {
		if (b & 1ll) r = r * a % m;
		a = a * a % m;
		b >>= 1ll;
	}
	return r;
}

int nck(int n, int k) {
	return fac[n] * exp_mod(fac[k], MOD - 2, MOD) % MOD * exp_mod(fac[n - k], MOD - 2, MOD) % MOD;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	fac[0] = 1;
	for (int i = 1; i <= M; i++) fac[i] = fac[i - 1] * i % MOD;
	for (int i = 1; i <= M + 1; i++)
		link[i] = i, sz[i] = 1;
	for (int i = 1, k, x, y; i <= N; i++) {
		cin >> k;
		if (k == 1) {
			cin >> x;
			T[i] = mt(i, x, M + 1);
		} else {
			cin >> x >> y;
			T[i] = mt(i, x, y);
		}
	}
	sort(T + 1, T + 1 + N);
	for (int i = 1, w, u, v; i <= N; i++) {
		tie(w, u, v) = T[i];
		if (find(u) != find(v)) {
			unite(u, v);
			ans.pb(w);
		}
	}
	set<ii> tmp;
	curr = 1;
	for (int i = 1; i <= M + 1; i++)
		tmp.emplace(sz[find(i)], find(i));
	for (auto i : tmp) {
		if (find(i.second) == find(M + 1)) curr = (curr * exp_mod(2, i.first - 1, 1e9 + 7)) % MOD;
		else {
			int tmp = 0;
			for (int j = 0; j <= sz[i.second]; j += 2)
				tmp = (tmp + nck(sz[i.second], j)) % MOD;
			curr = curr * tmp % MOD;
		}
	}
	cout << curr << ' ' << ans.size() << '\n';
	for (int j : ans) cout << j << ' ';
	cout << '\n';
}