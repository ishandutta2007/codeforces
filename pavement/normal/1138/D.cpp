#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#define putchar_unlocked _putchar_nolock
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
typedef double db;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

string S, T;
int pi[500005], cnt[2];

void prefix_function(string s) {
	int n = (int)s.length();
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> S >> T;
	if (T.size() > S.size()) return cout << S << '\n', 0;
	prefix_function(T);
	for (char c : S) cnt[c - '0']++;
	for (int i = 0, idx = 0; i < S.size(); i++) {
		if (!cnt[T[idx] - '0']) cout << char(!(T[idx] - '0') + '0'), cnt[!(T[idx] - '0')]--;
		else {
			cout << T[idx];
			cnt[T[idx] - '0']--;
			idx++;
			if (idx == T.size()) idx = pi[T.size() - 1];
		}
	}
	cout << '\n';
}