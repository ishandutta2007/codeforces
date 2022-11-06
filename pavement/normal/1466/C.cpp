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

int T;
string S;

char picknone(vector<char> v) {
	for (int i = 0; i < 26; i++) {
		bool inv = 0;
		for (char c : v)
			if (c == i + 'a') inv = 1;
		if (!inv) return i + 'a';
	}
	assert(false);
	return 'a';
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> S;
		int chng = 0;
		for (int i = 0; i < S.size(); i++) {
			vector<char> vec;
			bool cannot = 0;
			if (i >= 1) {
				cannot |= (S[i] == S[i - 1]);
				vec.pb(S[i - 1]);
			}
			if (i >= 2) {
				cannot |= (S[i] == S[i - 2]);
				vec.pb(S[i - 2]);
			}
			for (int j = i + 1; j < min((int)S.size(), i + 3); j++)
				vec.pb(S[j]);
			if (cannot) {
				S[i] = picknone(vec);
				chng++;
			}
		}
		cout << chng << '\n';
	}
}