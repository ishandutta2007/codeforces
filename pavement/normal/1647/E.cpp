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

int N, leaves, iter, mx, ptr = 1, P[35][100005], A[100005], B[100005];
bool is_leaf[100005];
vector<int> vec[100005];
set<int> to_use, tmp, ss[100005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		is_leaf[i] = 1;
		to_use.insert(i);
	}
	for (int i = 1; i <= N; i++) {
		cin >> P[0][i];
		is_leaf[P[0][i]] = 0;
	}
	for (int i = 1; i <= N; i++) leaves += is_leaf[i];
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		mx = max(mx, A[i]);
	}
	iter = (mx - N) / leaves;
	for (int i = 1; i <= 30; i++)
		for (int j = 1; j <= N; j++)
			P[i][j] = P[i - 1][P[i - 1][j]];
	for (int i = 1; i <= N; i++) {
		int curr = i;
		for (int k = 30; k >= 0; k--)
			if (iter & (1 << k)) curr = P[k][curr];
		ss[curr].insert(i);
	}
	for (int i = 1; i <= N; i++) {
		if (A[i] <= N) {
			assert(!ss[i].empty());
			B[*ss[i].begin()] = A[i];
			ss[i].erase(ss[i].begin());
			to_use.erase(A[i]);
			for (auto j : ss[i]) vec[A[i]].pb(j);
		} else assert(ss[i].empty());
	}
	for (auto i : to_use) {
		for (; ptr <= i; ptr++)
			for (auto j : vec[ptr]) tmp.insert(j);
		B[*tmp.begin()] = i;
		tmp.erase(tmp.begin());
	}
	for (int i = 1; i <= N; i++) cout << B[i] << ' ';
	cout << '\n';
}