#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()

template<class C> void mini(C &a5, C b5) { a5 = min(a5, b5); }
template<class C> void maxi(C &a5, C b5) { a5 = max(a5, b5); }

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1e18;
const int mod = 1e9 + 7;

const int max_n = 5010;

int dp[max_n][max_n];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string s, t;
    int n, m;
    cin >> n >> m >> s >> t;
    s = '#' + s;
    t = '#' + t;
    
    int res = 0;
    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) - 1;
			maxi(dp[i][j], dp[i - 1][j - 1] - 2);
			if (s[i] == t[j]) {
				maxi(dp[i][j], dp[i - 1][j - 1] + 2);
			}
			maxi(dp[i][j], 0ll);
			maxi(res, dp[i][j]);
		}
	}
	cout << res;
    
    return 0;
}/*

*/