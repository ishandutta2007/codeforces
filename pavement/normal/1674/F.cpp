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

int N, M, Q, idx, sz, cnt, ptr, num[1005][1005];
char C[1005][1005];
ii rev[1000005];

void inc() {
	ptr++;
	auto [x, y] = rev[ptr];
	if (C[x][y] == '*') cnt++;
}

void dec() {
	auto [x, y] = rev[ptr];
	if (C[x][y] == '*') cnt--;
	ptr--;
}

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			cin >> C[i][j];
			if (C[i][j] == '*') sz++;
		}
	for (int j = 1; j <= M; j++)
		for (int i = 1; i <= N; i++) {
			num[i][j] = ++idx;
			rev[idx] = mp(i, j);
		}
	for (int k = 0; k < sz; k++) inc();
	for (int x, y; Q--; ) {
		cin >> x >> y;
		if (C[x][y] == '*') {
			if (num[x][y] <= sz) cnt--;
			C[x][y] = '.';
			sz--;
			dec();
		} else {
			if (num[x][y] <= sz) cnt++;
			C[x][y] = '*';
			sz++;
			inc();
		}
		cout << sz - cnt << '\n';
	}
}