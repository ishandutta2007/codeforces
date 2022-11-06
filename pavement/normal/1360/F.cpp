#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#ifdef TEST
#define getchar_unlocked _getchar_nolock
#endif
#define ins insert
#define int long long
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
typedef tuple<int, int, int, int> iiii;
typedef tree<pair<ll, int>, null_type, less<pair<ll, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

string A[15];
int dp[15][2005], nxtone[15][2005], nxtmask[15][2005];

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T, N, M;
	cin >> T;
	while (T--) {
		memset(dp, 0, sizeof dp);
		memset(nxtone, 0, sizeof nxtone);
		memset(nxtmask, 0, sizeof nxtmask);
		cin >> N >> M;
		for (int i = 1; i <= N; i++) cin >> A[i];
		for (int i = M; i >= 1; i--)
			for (int j = 0; j < (1 << N); j++) {
				for (int k = 0; k < 26; k++) {
					int nxt = 0;
					for (int p = 1; p <= N; p++)
						if (A[p][i - 1] != k + 'a')
							nxt |= (1 << (p - 1));
					if (j & nxt) continue;
					if (i == M || dp[i + 1][j | nxt]) {
						dp[i][j] = 1;
						nxtone[i][j] = k;
						nxtmask[i][j] = nxt;
						break;
					}
				}
			}
		if (!dp[1][0]) cout << "-1\n";
		else {
			int curmask = 0;
			for (int i = 1; i <= M; i++) {
				cout << char(nxtone[i][curmask] + 'a');
				curmask |= nxtmask[i][curmask];
			}
			cout << '\n';
		}
	}
}