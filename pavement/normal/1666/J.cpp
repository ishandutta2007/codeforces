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

int N, mem[205][205], C[205][205], to[205][205], par[205];

int s(int r1, int r2, int c1, int c2) {
	return C[r2][c2] - C[r1 - 1][c2] - C[r2][c1 - 1] + C[r1 - 1][c1 - 1];
}

int dp(int l, int r) {
	if (l >= r) return 0;
	if (mem[l][r] != -1) return mem[l][r];
	auto ret = mp(LLONG_MAX, -1ll);
	for (int k = l; k <= r; k++) {
		ret = min(ret, mp(dp(l, k - 1) + s(l, k - 1, 1, l - 1) + s(l, k - 1, k, N)
					  + dp(k + 1, r) + s(k + 1, r, 1, k) + s(k + 1, r, r + 1, N), k));
	}
	to[l][r] = ret.second;
	return mem[l][r] = ret.first;
}

int get(int l, int r) {
	if (l == r) return l;
	if (l > r) return -1;
	dp(l, r);
	int k = to[l][r], lc = get(l, k - 1), rc = get(k + 1, r);
	if (lc != -1) par[lc] = k;
	if (rc != -1) par[rc] = k;
	return k;
}

main() {
	memset(mem, -1, sizeof mem);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> C[i][j];
			C[i][j] += C[i - 1][j] + C[i][j - 1] - C[i - 1][j - 1];
		}
	get(1, N);
	for (int i = 1; i <= N; i++) cout << par[i] << ' ';
	cout << '\n';
}