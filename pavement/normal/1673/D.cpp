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

const int MOD = 1e9 + 7;
int T, B, Q, Y, C, R, Z;
bool inv;

int exp_mod(int a, int b) {
	a %= MOD; // bruh!
	int r = 1;
	while (b) {
		if (b & 1ll) r = r * a % MOD;
		a = a * a % MOD;
		b >>= 1ll;
	}
	return r;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		inv = 0;
		cin >> B >> Q >> Y >> C >> R >> Z;
		// find k s.t. B + k * Q == C
		// k = (C - B) / Q
		if ((C - B) % Q != 0 || (C + (Z - 1) * R - B) % Q != 0) inv = 1;
		int k = (C - B) / Q, k2 = (C + (Z - 1) * R - B) / Q;
		if (0 <= k && k < Y && 0 <= k2 && k2 < Y) {
			if ((C - R - B) % Q || (C + Z * R - B) % Q) inv = 1;
			int k3 = ((C - R) - B) / Q, k4 = (C + Z * R - B) / Q;
			if (inv) cout << "0\n";
			else if (0 <= k3 && k3 < Y && 0 <= k4 && k4 < Y) {
				int ret = 0;
				for (int i = 1; i * i <= R; i++) {
					if (R % i == 0) {
						if (lcm(Q, i) == R) {
							//cout << "! " << i << '\n';
							ret += R * R % MOD * exp_mod(i * i, MOD - 2) % MOD;
							//cout << ret << '\n';
						}
						if (R / i > i && lcm(Q, R / i) == R) {
							//cout << "! " << R / i << '\n';
							ret += R * R % MOD * exp_mod((R / i) * (R / i), MOD - 2) % MOD;
							//cout << "^ " << ret << '\n';
						}
						ret %= MOD;
					}
				}
				cout << ret << '\n';
			} else cout << "-1\n";
		} else cout << "0\n";
	}
}