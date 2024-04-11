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
typedef long double ld;
typedef long long ll;
typedef tree<pair<int, int>, null_type, less<pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int N, M, G[105][105], F[105][105], R[105], C[105], _R[105], _C[105];
vector<int> rowans, colans, _rowans, _colans;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> G[i][j], F[i][j] = G[i][j];
	for (int i = 1; i <= N; i++) {
		int tmp = 1e9;
		for (int j = 1; j <= M; j++)
			tmp = min(tmp, G[i][j]);
		for (int j = 1; j <= M; j++)
			G[i][j] -= tmp;
		R[i] = tmp;
	}
	for (int j = 1; j <= M; j++) {
		int tmp = 1e9;
		for (int i = 1; i <= N; i++)
			tmp = min(tmp, G[i][j]);
		for (int i = 1; i <= N; i++)
			G[i][j] -= tmp;
		C[j] = tmp;
	}
	bool cannot = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (G[i][j]) cannot = 1;
	if (cannot) {
		memset(R, 0, sizeof R);
		memset(C, 0, sizeof C);
		for (int j = 1; j <= M; j++) {
			int tmp = 1e9;
			for (int i = 1; i <= N; i++)
				tmp = min(tmp, F[i][j]);
			for (int i = 1; i <= N; i++)
				F[i][j] -= tmp;
			C[j] = tmp;
		}
		for (int i = 1; i <= N; i++) {
			int tmp = 1e9;
			for (int j = 1; j <= M; j++)
				tmp = min(tmp, F[i][j]);
			for (int j = 1; j <= M; j++)
				F[i][j] -= tmp;
			R[i] = tmp;
		}
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				if (F[i][j]) return cout << "-1\n", 0;
	}
	for (int j = 1; j <= M; j++) {
		int tmp = 1e9;
		for (int i = 1; i <= N; i++)
			tmp = min(tmp, F[i][j]);
		for (int i = 1; i <= N; i++)
			F[i][j] -= tmp;
		_C[j] = tmp;
	}
	for (int i = 1; i <= N; i++) {
		int tmp = 1e9;
		for (int j = 1; j <= M; j++)
			tmp = min(tmp, F[i][j]);
		for (int j = 1; j <= M; j++)
			F[i][j] -= tmp;
		_R[i] = tmp;
	}
	for (int i = 1; i <= N; i++)
		for (int k = 1; k <= R[i]; k++)
			rowans.pb(i);
	for (int j = 1; j <= M; j++)
		for (int k = 1; k <= C[j]; k++)
			colans.pb(j);
	for (int i = 1; i <= N; i++)
		for (int k = 1; k <= _R[i]; k++)
			_rowans.pb(i);
	for (int j = 1; j <= M; j++)
		for (int k = 1; k <= _C[j]; k++)
			_colans.pb(j);
	if (_rowans.size() + _colans.size() < rowans.size() + colans.size()) {
		swap(rowans, _rowans);
		swap(colans, _colans);
	}
	cout << rowans.size() + colans.size() << '\n';
	for (int i : rowans) cout << "row " << i << '\n';
	for (int i : colans) cout << "col " << i << '\n';
}