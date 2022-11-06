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

int T, N, tot1, sum0, sum1;
string S;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> S;
		N = S.size();
		tot1 = 0;
		for (char c : S)
			if (c == '1') tot1++;
		int lo = 0, hi = N, ans = -1;
		while (lo <= hi) {
			sum0 = sum1 = 0;
			int mid = (lo + hi) >> 1, maxsum1 = 0;
			for (int i = 0, j = 0; i < N; i++) {
				if (S[i] == '0') sum0++;
				else sum1++;
				// find max j s.t. # zeroes in [j, i] <= mid
				while (sum0 > mid) {
					if (S[j] == '0') sum0--;
					else sum1--;
					j++;
				}
				maxsum1 = max(maxsum1, sum1);
			}
			if (tot1 - maxsum1 <= mid) ans = mid, hi = mid - 1;
			else lo = mid + 1;
		}
		cout << ans << '\n';
	}
}