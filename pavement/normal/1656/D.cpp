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

bool check(int x) {
	//cout << "! " << x << '\n';
	if (x <= 1e9 && x * (x + 1) / 2 <= N) {
		return N % x == (x * (x + 1) / 2) % x;
	}
	return 0;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> N;
		int ON = N;
		if (__builtin_popcountll(N) == 1) cout << "-1\n";
		else {
			while (N & 1ll ^ 1ll) N >>= 1ll;
			int tmp = N;
			N = ON;
			if (check(tmp)) cout << tmp << '\n';
			else {
				for (int k = 2; ; k *= 2)
					if (check(k)) {
						cout << k << '\n';
						break;
					}
			}
		}
	}
}