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
typedef long double ld;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, R, T;
bool A[1005], C[1005];
vector<int> can;

bool notin(int l, int r) {
	l = max(l, 1ll);
	r = min(r, N);
	for (int i = l; i <= r; i++)
		if (C[i]) return false;
	return true;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> R;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		if (A[i]) can.pb(i);
	}
	for (int i = 1; i <= N; i++) {
		if (notin(i - R + 1, i + R - 1)) {
			auto it = upper_bound(can.begin(), can.end(), i + R - 1);
			if (it == can.begin()) return cout << "-1\n", 0;
			--it;
			if (*it < i - R + 1) return cout << "-1\n", 0;
			C[*it] = 1;
			T++;
		}
	}
	cout << T << '\n';
}