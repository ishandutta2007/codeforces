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

int T, bcnt;
string U, V;
stack<char> s1, s2;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> U >> V;
		for (char c : U) {
			if (c == 'B') bcnt++;
			else {
				if (!s1.empty() && s1.top() == c) s1.pop();
				else s1.push(c);
			}
		}
		for (char c : V) {
			if (c == 'B') bcnt--;
			else {
				if (!s2.empty() && s2.top() == c) s2.pop();
				else s2.push(c);
			}
		}
		if (bcnt % 2 == 0 && s1 == s2) cout << "YES\n";
		else cout << "NO\n";
		bcnt = 0;
		while (!s1.empty()) s1.pop();
		while (!s2.empty()) s2.pop();
	}
}