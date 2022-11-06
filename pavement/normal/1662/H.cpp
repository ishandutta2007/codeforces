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

int T, W, L;

vector<int> fac(int x) {
	vector<int> ret;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			ret.pb(i);
			if (x / i > i) ret.pb(x / i);
		}
	}
	return ret;
}

bool valid1(int x) {
	int lft = W % x;
	if (lft > 1) return 0;
	lft = (L - 1 + lft) % x;
	if (lft > 1) return 0;
	lft = (W - 1 + lft) % x;
	if (lft > 1) return 0;
	lft = (L - 2 + lft) % x;
	return lft == 0;	
}

bool valid(int x) {
	bool ans = valid1(x);
	swap(L, W);
	ans |= valid1(x);
	swap(L, W);
	return ans;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> W >> L;
		set<int> S;
		vector<int> f1 = fac(W - 1), f2 = fac(W);
		for (int i : f1)
			if (valid(i)) S.insert(i);
		for (int i : f2)
			if (valid(i)) S.insert(i);
		f1 = fac(L - 1), f2 = fac(L);
		for (int i : f1)
			if (valid(i)) S.insert(i);
		for (int i : f2)
			if (valid(i)) S.insert(i);
		cout << S.size() << ' ';
		for (int i : S) cout << i << ' ';
		cout << '\n';
	}
}