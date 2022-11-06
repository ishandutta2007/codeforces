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
using ordered_set = tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update>;

int N, Q, X[300005], W[300005], out[300005], ft[300005];
stack<int> st;
vector<int> segs[300005];
vector<ii> vec[300005];

inline int ls(int x) { return x & -x; }

int qry(int p) {
	int r = LLONG_MAX;
	for (p = N - p + 1; p; p -= ls(p)) r = min(r, ft[p]);
	return r;
}

void upd(int p, int v) {
	for (p = N - p + 1; p <= N; p += ls(p)) ft[p] = min(ft[p], v);
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> X[i] >> W[i];
		ft[i] = LLONG_MAX;
	}
	for (int i = 1, L, R; i <= Q; i++) {
		cin >> L >> R;
		vec[R].eb(L, i);
	}
	for (int i = 1; i <= N; i++) {
		while (!st.empty() && W[st.top()] > W[i]) st.pop();
		if (!st.empty()) segs[i].pb(st.top());
		st.push(i);
	}
	while (!st.empty()) st.pop();
	for (int i = N; i >= 1; i--) {
		while (!st.empty() && W[st.top()] > W[i]) st.pop();
		if (!st.empty()) segs[st.top()].pb(i);
		st.push(i);
	}
	for (int i = 1; i <= N; i++) {
		for (auto j : segs[i]) upd(j, (W[i] + W[j]) * (X[i] - X[j]));
		for (auto [j, idx] : vec[i]) out[idx] = qry(j);
	}
	for (int i = 1; i <= Q; i++) cout << out[i] << '\n';
}