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

int T, dp[2][405][405];
string s, t;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--) {
		cin >> s >> t;
		
		for (int a = 0; a <= t.size(); a++)
			for (int b = 0; b <= t.size(); b++)
				dp[s.size() & 1][a][b] = (b == t.size() ? a : 0ll);
		
		for (int n = (int)s.size() - 1; n >= 0; n--)
			for (int a = 0; a <= t.size(); a++)
				for (int b = 0; b <= t.size(); b++) {
					if (a == t.size() && b == t.size()) dp[n & 1][a][b] = t.size();
					else if (b == t.size()) {
						if (s[n] == t[a]) dp[n & 1][a][b] = dp[n & 1 ^ 1][a + 1][b];
						else dp[n & 1][a][b] = dp[n & 1 ^ 1][a][b];
					} else if (a == t.size()) {
						if (s[n] == t[b]) dp[n & 1][a][b] = dp[n & 1 ^ 1][a][b + 1];
						else dp[n & 1][a][b] = dp[n & 1 ^ 1][a][b];
					} else {
						int ans = dp[n & 1 ^ 1][a][b];
						if (s[n] == t[a]) ans = max(ans, dp[n & 1 ^ 1][a + 1][b]);
						if (s[n] == t[b]) ans = max(ans, dp[n & 1 ^ 1][a][b + 1]);
						dp[n & 1][a][b] = ans;
					}
				}
		
		bool ans = 0;
		for (int i = 1; i <= t.size(); i++) ans |= (dp[0][0][i] >= i);
		cout << (ans ? "YES" : "NO") << '\n';
	}
}