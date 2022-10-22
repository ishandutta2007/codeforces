#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <iomanip>
#include <cassert>
using namespace std;
#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long
const int N = 2e5 + 3;
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(6);
	int tt; cin >> tt;
	while (tt --> 0){
	    int n; cin >> n;
	    vector <int> dp(N), cnt(N);
	    for (int i = 0; i < n; ++i) {
	        int x; cin >> x;
	        cnt[x]++;
	    }
	    for (int i = 1; i < N; ++i){
	        dp[i] = max(dp[i], cnt[i]);
	        for (int j = i + i; j < N; j += i){
	            dp[j] = max(dp[j], cnt[j] + dp[i]);
	        }
	    }
	    int ans = 0;
	    for (auto &x: dp) ans = max(ans, x);
	    cout << n - ans << '\n';
	}
	return 0;
}