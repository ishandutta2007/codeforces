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
 
int N, M;
ii w[505];
string S;
 
main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		string tmp = "";
		for (int j = 1; j <= M; j++)
			if (i == j) tmp += "1";
			else tmp += "0";
		cout << "? " << tmp << endl;
		cin >> w[i].first;
		w[i].second = i;
	}
	sort(w + 1, w + 1 + M);
	for (int i = 0; i < M; i++) S += "0";
	int curr, res = 0, ans = 0;
	for (int i = 1, ww, idx; i <= M; i++) {
		tie(ww, idx) = w[i];
		S[idx - 1] = '1';
		cout << "? " << S << endl;
		cin >> curr;
		if (curr == res + ww) ans += ww, res = curr;
		else S[idx - 1] = '0';
	}
	cout << "! " << ans << endl;
}