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
#define g4(a) get<4>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using db = double;
using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using iii = tuple<int, int, int>;
using iiii = tuple<int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 998244353;
int T, N, M, A[200005];
bitset<1000005> ip;
vector<int> primes;

vector<int> _pf(int x) {
	vector<int> ret;
	for (int i : primes)
		while (x % i == 0) {
			ret.pb(i);
			x /= i;
		}
	if (x != 1) ret.pb(x);
	sort(ret.begin(), ret.end());
	ret.erase(unique(ret.begin(), ret.end()), ret.end());
	return ret;
}

main() {
	ip.set();
	ip[0] = ip[1] = 0;
	for (int i = 2; i <= (int)1e6; i++) {
		if (!ip[i]) continue;
		primes.pb(i);
		for (int j = i + i; j <= (int)1e6; j += i)
			ip[j] = 0;
	}
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		int ans = 1;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
		}
		for (int i = 2; i <= N; i++) {
			if (A[i] == A[i - 1]) {
				ans *= M / A[i];
				ans %= MOD;
			} else if (A[i - 1] >= A[i] && A[i - 1] % A[i] == 0) {
				auto pf = _pf(A[i - 1] / A[i]);
				//~ for (auto j : pf) cout << j << ' ';
				//~ cout << '\n';
				int tmp = 0;
				for (int j = 1; j < (1ll << (int)pf.size()); j++) {
					int curr = 1;
					for (int k = 0; k < (int)pf.size(); k++) {
						if (j & (1ll << k)) {
							curr *= pf[k];
						}
					}
					//~ cout << curr << ' ' << i << ' ' << M << ' ' << A[i] << ' ' << ((M / A[i]) / curr) << '\n';
					tmp += (__builtin_popcountll(j) % 2 == 1 ? 1 : -1) * ((M / A[i]) / curr);
					tmp %= MOD;
				}
				//~ cout << tmp << '\n';
				ans *= ((M / A[i]) - tmp) % MOD;
				ans %= MOD;
			} else {
				ans = 0;
				break;
			}
		}
		cout << (ans + MOD) % MOD << '\n';
	}
}