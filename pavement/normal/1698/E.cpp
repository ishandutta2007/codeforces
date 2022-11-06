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
using iiiii = tuple<int, int, int, int, int>;
template<class key, class value = null_type, class cmp = less<key> >
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 998244353;
int T, N, S, nS, ans = 1, A[200005], B[200005], idx[200005], cnt[200005];
bool inv, has[200005];
vector<int> L, valid;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> S;
		for (int i = 1; i <= N; i++) {
			cin >> A[i];
			idx[i] = i;
		}
		for (int i = 1; i <= N; i++) {
			cin >> B[i];
			if (B[i] != -1) nS = max(nS, A[i] - B[i]);
		}
		if (nS > S) ans = 0;
		sort(idx + 1, idx + 1 + N, [](const auto &lhs, const auto &rhs) {
			return A[lhs] < A[rhs];
		});
		for (int i = 1; i <= N; i++) idx[i] = B[idx[i]];
		swap(B, idx);
		for (int i = 1; i <= N; i++)
			if (B[i] != -1) has[B[i]] = 1;
		for (int i = 1; i <= N; i++)
			if (!has[i]) valid.pb(i);
		for (int i = 1; i <= N; i++) {
			if (B[i] == -1) {
				int lo = 0, hi = (int)valid.size() - 1, l = -1;
				while (lo <= hi) {
					int mid = (lo + hi) >> 1;
					// A[i] - B[i] <= S
					if (i - valid[mid] <= S) l = mid, hi = mid - 1;
					else lo = mid + 1;
				}
				if (l == -1) inv = 1;
				L.pb(valid.size() - l);
			}
		}
		if (inv) ans = 0;
		sort(L.begin(), L.end());
		for (int i = 0; i < L.size(); i++)
			ans = (ans * (L[i] - i)) % MOD;
		cout << ans << '\n';
		valid.clear();
		L.clear();
		ans = 1;
		inv = nS = 0;
		for (int i = 1; i <= N; i++) {
			A[i] = idx[i] = B[i] = has[i] = cnt[i] = 0;
		}
	}
}