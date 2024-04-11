#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif
//#define int long long
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

int N, M, P[5000005], diff[5000005];
char C[5000005], out[5000005];
bool tmp[5000005];

int conv(int r, int c) {
	assert(0 <= r && r <= N + 1 && 0 <= c && c <= M + 1);
	return r * (M + 2) + c;
}

int sum(int r1, int c1, int r2, int c2) {
	return P[conv(r2, c2)] - P[conv(r1 - 1, c2)] - P[conv(r2, c1 - 1)] + P[conv(r1 - 1, c1 - 1)];
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> C[conv(i, j)];
			P[conv(i, j)] = (C[conv(i, j)] == 'X') + P[conv(i - 1, j)] + P[conv(i, j - 1)] - P[conv(i - 1, j - 1)];
		}
	int lo = 0, hi = N * M, ans = -1;
	while (lo <= hi) {
		int mid = (lo + hi) >> 1;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++) {
				if (i - mid >= 1 && i + mid <= N && j - mid >= 1 && j + mid <= M && sum(i - mid, j - mid, i + mid, j + mid) == (2 * mid + 1) * (2 * mid + 1)) {
					diff[conv(i - mid, j - mid)]++;
					diff[conv(i + mid + 1, j - mid)]--;
					diff[conv(i - mid, j + mid + 1)]--;
					diff[conv(i + mid + 1, j + mid + 1)]++;
					tmp[conv(i, j)] = 1;
				}
			}
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				diff[conv(i, j)] += diff[conv(i - 1, j)] + diff[conv(i, j - 1)] - diff[conv(i - 1, j - 1)];
		bool inv = 0;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (C[conv(i, j)] == 'X' && diff[conv(i, j)] == 0) inv = 1;
		if (!inv) {
			ans = mid, lo = mid + 1;
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= M; j++)
					out[conv(i, j)] = (tmp[conv(i, j)] ? 'X' : '.');
		} else hi = mid - 1;
		for (int i = 0; i <= N + 1; i++)
			for (int j = 0; j <= M + 1; j++) diff[conv(i, j)] = tmp[conv(i, j)] = 0;
	}
	cout << ans << '\n';
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cout << out[conv(i, j)];
		cout << '\n';
	}
}