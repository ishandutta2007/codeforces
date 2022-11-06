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

int Q, minl[65], maxl[65], sz[65], v1[65], v2[65];

int layer(int k) {
	for (int i = 0; i < 60; i++)
		if (minl[i] <= k && k <= maxl[i]) return i;
	assert(0);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> Q;
	for (int i = 0; i < 60; i++) {
		minl[i] = (1ll << i);
		maxl[i] = (1ll << (i + 1)) - 1;
		sz[i] = maxl[i] - minl[i] + 1;
	}
	for (int t, x, k; Q--; ) {
		cin >> t;
		if (t == 1) {
			cin >> x >> k;
			int l = layer(x);
			k = (k % sz[l] + sz[l]) % sz[l];
			v1[l] = (v1[l] + k) % sz[l];
		} else if (t == 2) {
			cin >> x >> k;
			int l = layer(x);
			k = (k % sz[l] + sz[l]) % sz[l];
			v2[l] = (v2[l] + k) % sz[l];
		} else {
			cin >> x;
			int l = layer(x);
			x += v1[l];
			if (x > maxl[l]) x = minl[l] + (x - maxl[l] - 1);
			while (x != 1) {
				int tmp = x - v1[l];
				if (tmp < minl[l]) tmp = maxl[l] - (minl[l] - tmp - 1);
				cout << tmp << ' ';
				x += v2[l];
				if (x > maxl[l]) x = minl[l] + (x - maxl[l] - 1);
				x /= 2;
				l--;
			}
			cout << "1\n";
		}
	}
}