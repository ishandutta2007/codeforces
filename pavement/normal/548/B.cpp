#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
typedef long double ld;

int N, M, Q, cnt[505];
bool F[505][505];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> F[i][j];
	for (int i = 1; i <= N; i++) {
		int ms = 0, rs = 0;
		for (int y = 1; y <= M; y++)
			if (!F[i][y]) {
				ms = max(ms, rs);
				rs = 0;
			} else rs++;
		ms = max(ms, rs);
		cnt[i] = ms;
	}
	for (int i, j; Q--; ) {
		cin >> i >> j;
		F[i][j] = !F[i][j];
		int ms = 0, rs = 0;
		for (int y = 1; y <= M; y++)
			if (!F[i][y]) {
				ms = max(ms, rs);
				rs = 0;
			} else rs++;
		ms = max(ms, rs);
		cnt[i] = ms;
		int tm = 0;
		for (int y = 1; y <= N; y++)
			tm = max(tm, cnt[y]);
		cout << tm << '\n';
	}
}