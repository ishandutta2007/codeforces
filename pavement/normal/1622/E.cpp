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
typedef double db;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef tuple<int, int, int, int> iiii;
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int T, N, M, ans, X[15], out[10005];
ii coeff[10005];
bool B[15][10005];
char C;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		ans = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) cin >> X[i];
		for (int i = 0; i < N; i++)
			for (int j = 1; j <= M; j++) {
				cin >> C;
				B[i][j] = (C - '0');
			}
		for (int i = 0; i < (1 << N); i++) {
			for (int j = 1; j <= M; j++) coeff[j].first = 0, coeff[j].second = j;
			int curr = 0;
			for (int j = 0; j < N; j++) {
				if (i & (1 << j)) {
					for (int k = 1; k <= M; k++)
						if (B[j][k]) coeff[k].first--;
					curr += X[j];
				} else {
					for (int k = 1; k <= M; k++)
						if (B[j][k]) coeff[k].first++;
					curr -= X[j];
				}
			}
			//cout << "# " << i << '\n';
			//for (int j = 1; j <= M; j++) cout << coeff[j].first << ' ';
			//cout << '\n';

			sort(coeff + 1, coeff + 1 + M);
			for (int j = 1; j <= M; j++) {
				curr += coeff[j].first * j;
			}
			//cout << curr << '\n';
			if (curr >= ans) {
				for (int j = 1; j <= M; j++) {
					out[coeff[j].second] = j;
					//cout << coeff[j].second << " --> " << j << '\n';
				}
				ans = curr;
			}
		}	
		for (int i = 1; i <= M; i++) cout << out[i] << ' ';
		cout << '\n';
	}
}