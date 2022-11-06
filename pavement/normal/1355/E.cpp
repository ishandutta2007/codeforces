#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, A, R, M, cst = LLONG_MAX, H[100005], P[100005];
vector<ii> V;

int f(int i) {
	auto it = upper_bound(H + 1, H + 1 + N, i);
	int cur = it - (H + 1), lhs = cur * i - P[cur], rhs = P[N] - P[cur] - (N - cur) * i;
	return min(lhs, rhs) * M + A * (lhs - min(lhs, rhs)) + R * (rhs - min(lhs, rhs));
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> A >> R >> M;
	M = min(M, A + R);
	for (int i = 1; i <= N; i++) cin >> H[i];
	sort(H + 1, H + 1 + N);
	for (int i = 1; i <= N; i++) P[i] = P[i - 1] + H[i];
	for (int i = 1; i <= N; i++)
		cst = min(cst, f(H[i]));
	for (int i = 1; i < N; i++)
		if (H[i + 1] > H[i] + 1) V.eb(H[i] + 1, H[i + 1] - 1);
	for (auto i : V) {
		int lo = i.first, hi = i.second;
		while (hi - lo >= 3) {
			int m1 = lo + (hi - lo) / 3, m2 = hi - (hi - lo) / 3, c1 = f(m1), c2 = f(m2);
			if (c1 > c2) lo = m1;
			else hi = m2;
		}
		for (int j = lo; j <= hi; j++) cst = min(cst, f(j));
	}
	cout << cst << '\n';
}