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

int T, N, M, K;
string A, B;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N >> M >> K >> A >> B;
		sort(A.begin(), A.end(), greater<char>());
		sort(B.begin(), B.end(), greater<char>());
		bool ty = 0;
		int curr = 0;
		for (int i = 0; i < N + M; i++) {
			if (A.empty() || B.empty()) break;
			bool doa = 0, dob = 0;
			if (A.back() > B.back()) {
				if (ty == 1 && curr == K) doa = 1;
				else dob = 1;
			} else {
				if (ty == 0 && curr == K) dob = 1;
				else doa = 1;
			}
			assert(doa ^ dob);
			if (doa) cout << A.back(), A.ppb();
			else cout << B.back(), B.ppb();
			if (ty != dob) {
				ty = dob;
				curr = 1;
			} else curr++;
		}
		cout << '\n';
	}
}