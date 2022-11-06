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

int T, N, K, B[(1 << 21) + 5], pre[(1 << 21) + 5][3], ret[(1 << 21) + 5];

bool is_odd(int m, int n) {
	for (int i = 0; i < 30; i++)
		if (n & (1ll << i)) {
			if (!(m & (1ll << i))) return 0;
		}
	return 1;
}

bool odd(int l, int r) {
	int tk = r - l, fc = 0;
	if (l != 1) tk++, fc++;
	if (r != N) tk++, fc++;
	if (pre[N - tk - 1][fc] != -1) return pre[N - tk - 1][fc];
	// find parity of sum of nck(N - tk - 1, k) for all K - fc <= k
	bool ret = 0;
	for (int k = K - fc; k <= N - tk - 1; k++)
		ret ^= is_odd(N - tk - 1, k);
	pre[N - tk - 1][fc] = ret;
	return ret;
}

main() {
	memset(pre, -1, sizeof pre);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> B[i];
	for (int i = 1; i <= N; i++) {
		int s = 0;
		if (odd(i, i)) ret[B[i]] ^= 1;
		for (int j = i; j > 1; j--) {
			s += B[j];
			if (s >= 20) break;
			if (odd(j - 1, i) && (1 << s) * B[j - 1] < (1 << 20)) ret[(1 << s) * B[j - 1]] ^= 1;
		}
	}
	bool pr = 0;
	for (int i = (1 << 20) - 1; i >= 0; i--) {
		if (ret[i]) pr = 1;
		if (pr) cout << ret[i];
	}
	if (!pr) cout << 0;
	cout << '\n';
}