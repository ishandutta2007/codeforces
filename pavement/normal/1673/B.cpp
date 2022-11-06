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

int T;
string S;
bool has[35];
vector<int> vec[35];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> S;
		for (int i = 0; i < 26; i++) {
			has[i] = 0;
			vec[i].clear();
		}
		for (int i = 0; i < S.size(); i++) {
			has[S[i] - 'a'] = 1;
			vec[S[i] - 'a'].pb(i);
		}
		bool inv = 0;
		for (int i = 0; i < 26; i++)
			for (int j = i + 1; j < 26; j++) {
				if (!has[i] || !has[j]) continue;
				vector<ii> tmpp;
				for (int k : vec[i]) tmpp.eb(k, 0);
				for (int k : vec[j]) tmpp.eb(k, 1);
				sort(tmpp.begin(), tmpp.end());
				for (int k = 1; k < tmpp.size(); k++) {
					if (tmpp[k].second == tmpp[k - 1].second) {
						inv = 1;
						break;
					}
				}
			}
		if (inv) cout << "NO\n";
		else cout << "YES\n";
	}
}