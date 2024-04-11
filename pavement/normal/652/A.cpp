#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
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
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int H1, H2, A, B;
	cin >> H1 >> H2 >> A >> B;
	H1 -= 4 * A;
	if (H1 + 12 * A >= H2) {
		cout << "0\n";
		return 0;
	}
	if (A < B) return cout << "-1\n", 0;
	if (A == B && H1 + 12 * A < H2) return cout << "-1\n", 0;
	for (int d = 0; H1 < H2; d++) {
		if (H1 + 12 * A >= H2) return cout << d << '\n', 0;
		H1 += 12 * A;
		H1 -= 12 * B;
	}
	assert(false);
}