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

int N, X, Y, R, msk;
vector<int> vec;

main() {
	cin >> N >> X >> Y;
	for (int i = 0; i < 10; i++) {
		vector<int> vec1;
		for (int j = 1; j <= N; j++)
			if (j & (1 << i)) vec1.pb(j);
		if (vec1.empty()) continue;
		cout << "? " << vec1.size() << ' ';
		for (int j : vec1) cout << j << ' ';
		cout << endl;
		cin >> R;
		if (R == Y || R == (X ^ Y)) {
			msk |= (1 << i);
			vec = vec1;
		}
	}
	int lo = 0, hi = (int)vec.size() - 1, ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		vector<int> vec1;
		for (int i = 0; i <= mid; i++) vec1.pb(vec[i]);
		cout << "? " << vec1.size() << ' ';
		for (int j : vec1) cout << j << ' ';
		cout << endl;
		cin >> R;
		if (R == Y || R == (X ^ Y)) {
			ans = mid;
			hi = mid - 1;
		} else lo = mid + 1;
	}
	assert(ans != -1);
	int p1 = vec[ans], p2 = p1 ^ msk;
	if (p1 > p2) swap(p1, p2);
	cout << "! " << p1 << ' ' << p2 << endl;
}