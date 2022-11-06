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

int TC, N;
string S;
bool occ[26], hv[26];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> TC;
	while (TC--) {
		memset(occ, 0, sizeof occ);
		memset(hv, 0, sizeof hv);
		cin >> N;
		for (int i = 1; i <= 2 * N + 1; i++) {
			cin >> S;
			for (char c : S)
				occ[c - 'a'] ^= 1;
			if (S.size() == 1)
				hv[S[0] - 'a'] = 1;
		}
		for (int i = 0; i < 26; i++)
			if (occ[i] == 1 && hv[i]) cout << (char)(i + 'a') << '\n';
	}
}