#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

int n;
string s[2];
int dp[MAXN];

void solve() {
    cin >> n;
    cin >> s[0] >> s[1];
    int p_0 = -1, p_1 = -1;

    auto get = [&](int i) {
        if (i < 0) return 0;
        return dp[i];
    };

    for (int i = 0; i < n; i++) {
        if (s[0][i] == '0' || s[1][i] == '0') p_0 = i;
        if (s[0][i] == '1' || s[1][i] == '1') p_1 = i;

        dp[i] = 0;
        if (p_0 != -1) dp[i] = max(dp[i], get(p_0-1)+1);
        if (p_1 != -1 && p_0 != -1) dp[i] = max(dp[i], get(min(p_1, p_0)-1)+2);
        if (i) dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n-1] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}