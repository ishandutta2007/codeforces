#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
//~ #define int long long
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

const int K = 30, MOD = 998244353;
int N, Q, A[300005], B[300005], base_A[300005], base_x[300005], t[300005], idx[300005], x[300005], l[3000005], r[300005], k[300005];
ll ft[300005];
bool inv[300005];
gp_hash_table<int, int> mem;
uniform_int_distribution<> distrib(INT_MIN, INT_MAX);

int ls(int x) { return x & -x; }

void upd(int p, ll v) {
	for (; p <= N; p += ls(p)) ft[p] += v;
}

ll qry(int p) {
	ll r = 0;
	for (; p; p -= ls(p)) r += ft[p];
	return r;
}

int hsh(int x) {
	if (mem.find(x) != mem.end()) return mem[x];
	return mem[x] = distrib(rng);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		base_A[i] = hsh(A[i]);
	}
	for (int i = 1; i <= Q; i++) {
		cin >> t[i];
		if (t[i] == 1) {
			cin >> idx[i] >> x[i];
			base_x[i] = hsh(x[i]);
		} else cin >> l[i] >> r[i] >> k[i];
	}
	for (int j = 0; j <= K; j++) {
		for (int i = 1; i <= N; i++) {
			A[i] = ((ll)A[i] * (ll)base_A[i]) % MOD;
			B[i] = A[i];
			ft[i] = A[i];
		}
		for (int i = 1; i <= N; i++) {
			if (i + ls(i) <= N) ft[i + ls(i)] += ft[i];
		}
		for (int i = 1; i <= Q; i++) {
			if (t[i] == 1) {
				x[i] = ((ll)x[i] * (ll)base_x[i]) % MOD;
				upd(idx[i], (ll)x[i] - (ll)B[idx[i]]);
				B[idx[i]] = x[i];
			} else {
				if ((qry(r[i]) - qry(l[i] - 1)) % k[i]) inv[i] = 1;
			}
		}
	}
	for (int i = 1; i <= Q; i++) {
		if (t[i] == 1) continue;
		if (inv[i]) cout << "NO\n";
		else cout << "YES\n";
	}
}