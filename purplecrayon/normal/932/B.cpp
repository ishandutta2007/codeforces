#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 1e9+7;

int f(int n) {
    int ans = 1;
    while (n) {
        if (n % 10)
            ans *= n % 10;
        n /= 10;
    }
    return ans;
}
int sum[N][10];
int dp[N];

void solve() {
    for (int i = 0; i < N; i++) {
        if (i < 10) dp[i] = i;
        else {
            dp[i] = dp[f(i)];
        }
        if (dp[i] < 10) sum[i][dp[i]]++; 
    }
    for (int k = 0; k < 10; k++) {
        for (int i = 1; i < N; i++)
            sum[i][k] += sum[i-1][k];
    }
    int q; cin >> q;
    while (q--) {
        int l, r, k; cin >> l >> r >> k;
        cout << sum[r][k] - sum[l-1][k] << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}