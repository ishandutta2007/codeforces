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

int T, N, M, A[105][105], dp[105][105];
bool inv[105][105];
vector<int> st;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		st.clear();
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++) cin >> A[i][j];
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= M; j++)
				st.pb(A[i][j] - (i - 1 + j - 1));
		sort(st.begin(), st.end());
		int ttmin = LLONG_MAX;
		for (auto it = st.begin(); it != st.end(); ++it) {
			memset(inv, 0, sizeof inv);
			for (int i = 1; i <= N; i++) inv[i][0] = 1;
			for (int j = 1; j <= M; j++) inv[0][j] = 1;
			for (int i = 1; i <= N; i++)
				for (int j = 1; j <= M; j++) {
					if (*it + i - 1 + j - 1 > A[i][j]) {
						inv[i][j] = 1;
					} else {
						dp[i][j] = (A[i][j] - (*it + i - 1 + j - 1));
						if (i == 1 && j == 1) continue;
						inv[i][j] = inv[i - 1][j] && inv[i][j - 1];
						if (!inv[i][j]) {
							int tmp2 = LLONG_MAX;
							if (!inv[i - 1][j]) tmp2 = min(tmp2, dp[i - 1][j]);
							if (!inv[i][j - 1]) tmp2 = min(tmp2, dp[i][j - 1]);
							dp[i][j] += tmp2;
						}
					}
				}
			if (!inv[N][M]) ttmin = min(ttmin, dp[N][M]);
		}
		cout << ttmin << '\n';
	}
}