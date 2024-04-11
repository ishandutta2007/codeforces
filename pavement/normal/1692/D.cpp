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

int T, x, ans;
string S;
bool seen[24 * 60 + 5];

string conv(int t) {
	int h = t / 60, m = t % 60;
	string ret = "";
	if (h < 10) ret = "0" + to_string(h);
	else ret = to_string(h);
	if (m < 10) ret += "0" + to_string(m);
	else ret += to_string(m);
	return ret;
}

bool pal(string s) {
	string tmp = s;
	reverse(tmp.begin(), tmp.end());
	return s == tmp;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		memset(seen, 0, sizeof seen);
		ans = 0;
		cin >> S >> x;
		int t = ((S[0] - '0') * 10 + (S[1] - '0')) * 60 + ((S[3] - '0') * 10 + (S[4] - '0'));
		do {
			if (pal(conv(t))) ans++;
			seen[t] = 1;
			t += x;
			t %= 24 * 60;
		} while (!seen[t]);
		cout << ans << '\n';
	}
}