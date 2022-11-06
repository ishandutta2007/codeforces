#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define int long long
#define ins insert
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define pp pop
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define g0(a) get<0>(a)
#define g1(a) get<1>(a)
#define g2(a) get<2>(a)
#define g3(a) get<3>(a)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long double ld;
typedef long long ll;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	string s;
	cin >> t;
	while (t--) {
		cin >> s;
		set<char> dis;
		for (char c : s) dis.insert(c);
		if (dis.size() == 1) {
			cout << s << '\n';
			continue;
		}
		int add = 0;
		for (int i = 0; i < s.size() - 1; i++) {
			cout << s[i];
			if (s[i + 1] == s[i]) cout << char(!(s[i] - '0') + '0'), add++;
		}
		cout << s.back();
		if ((s.size() + add) & 1) cout << char(!(s.back() - '0') + '0');
		cout << '\n';
	}
}