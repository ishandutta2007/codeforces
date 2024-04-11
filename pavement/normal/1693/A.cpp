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

int T, N;
vector<int> A, add, sub;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		A.clear();
		add.clear();
		sub.clear();
		cin >> N;
		int s = 0;
		bool inv = 0;
		A.resize(N);
		for (int &i : A) cin >> i;
		while (A.back() == 0) A.ppb();
		if (A.empty()) {
			cout << "Yes\n";
			continue;
		}
		for (int i : A) s += i;
		if (s) {
			cout << "No\n";
			continue;
		}
		add.resize(A.size());
		sub.resize(A.size());
		sub[A.size() - 1] = -A.back();
		add[0] = 0;
		for (int i = (int)A.size() - 1; i >= 1; i--) {
			add[i - 1] = sub[i];
			sub[i - 1] = add[i - 1] - A[i - 1];
		}
		for (int i = 0; i < A.size(); i++) {
			if (i != A.size() - 1 && add[i] <= 0) inv = 1;
			if (i != 0 && sub[i] <= 0) inv = 1;
		}
		if (!sub[0] && !inv) cout << "Yes\n";
		else cout << "No\n";
	}
}