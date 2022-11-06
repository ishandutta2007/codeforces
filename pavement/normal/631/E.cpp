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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, R = LLONG_MIN, B[200005], A[200005], D[200005];
vector<iii> C;
set<iii> S;

ld is(int a, int b, int c, int d) { return (ld)(d - b) / (a - c); }

void insert_left(int m, int c) {
	for (int T = C.size(); T > 1; T--)
		if (is(g1(C.back()), g2(C.back()), m, c) <= is(g1(C[T - 2]), g2(C[T - 2]), m, c)) {
			S.erase(C.back());
			C.ppb();
		} else break;
	C.eb((C.empty() ? -1e9 : is(g1(C.back()), g2(C.back()), m, c)), m, c);
	S.ins(C.back());
}

void insert_right(int m, int c) {
	for (int T = C.size(); T > 1; T--)
		if (is(g1(C.back()), g2(C.back()), m, c) >= is(g1(C[T - 2]), g2(C[T - 2]), m, c)) {
			S.erase(C.back());
			C.ppb();
		} else break;
	C.eb((C.empty() ? 1e9 : is(g1(C.back()), g2(C.back()), m, c)), m, c);
	S.ins(C.back());
}

int qry_left(int x) {
	auto it = S.upper_bound(mt(x, 1e9, 1e9));
	--it;
	return g1(*it) * x + g2(*it);
}

int qry_right(int x) {
	auto it = S.lower_bound(mt(x, -1, -1));
	return g1(*it) * x + g2(*it);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		D[i] = D[i - 1] + A[i] * i;
		B[i] = B[i - 1] + A[i] * (i + 1);
	}
	for (int i = 1; i <= N; i++) {
		insert_left(i, D[i - 1] - B[i - 1]);
		R = max(R, qry_left(A[i]) + B[i - 1] + D[N] - D[i]);
	}
	for (int i = 1; i <= N; i++)
		B[i] = B[i - 1] + A[i] * (i - 1);
	C.clear();
	S.clear();
	for (int i = N; i >= 1; i--) {
		insert_right(i, B[i] - D[i]);
		R = max(R, qry_right(A[i]) - B[i] + D[N] + D[i - 1]);
	}
	cout << R << '\n';
}