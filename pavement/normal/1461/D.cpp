#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#ifdef WIN_32
#define getchar_unlocked _getchar_nolock
#endif
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
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
typedef long double ld;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, Q, A[100005], P[100005];
unordered_set<int> can;

int f(int l, int r) {
	auto it = lower_bound(A + 1, A + 1 + N, l);
	auto it2 = upper_bound(A + 1, A + 1 + N, r);
	if (it2 == A + 1) return 0;
	--it2;
	return P[it2 - A] - P[it - A - 1];
}

void rec(int l, int r) {
	if (l == r) {
		can.insert(f(l, r));
		return;
	}
	int m = (l + r) >> 1;
	auto it = upper_bound(A + 1, A + 1 + N, m);
	can.insert(f(l, m));
	can.insert(f(m + 1, r));
	if (it - A - 1 >= 1) rec(l, A[it - A - 1]);
	if (it != A + 1 + N) rec(*it, r);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		can.clear();
		cin >> N >> Q;
		for (int i = 1; i <= N; i++) cin >> A[i];
		sort(A + 1, A + 1 + N);
		for (int i = 1; i <= N; i++) P[i] = P[i - 1] + A[i];
		rec(A[1], A[N]);
		for (int i = 1; i <= Q; i++) {
			int s;
			cin >> s;
			cout << (P[N] == s || can.count(s) ? "Yes" : "No") << '\n';
		}
	}
}