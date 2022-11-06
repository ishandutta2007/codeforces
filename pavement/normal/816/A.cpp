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

string inc(string s) {
	if (s[1] == '9') {
		s[0]++;
		s[1] = '0';
	} else s[1]++;
	return s;
}

bool ip(string a, string b) {
	reverse(a.begin(), a.end());
	return a == b;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	string h = s.substr(0, 2), m = s.substr(3);
	if (ip(h, m)) return cout << "0\n", 0;
	for (int cnt = 1; true; cnt++) {
		m = inc(m);
		if (m == "60") {
			h = inc(h);
			if (h == "24") h = "00";
			m = "00";
		}
		if (ip(h, m)) {
			cout << cnt << '\n';
			return 0;
		}
	}
}