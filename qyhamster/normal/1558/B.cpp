#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e6 + 10;
long long dp[maxn], s[maxn], w[maxn];
bool ip[maxn];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    dp[1] = s[1] = 1;
    for(int i = 2; i <= n; i++) {
        w[i] = (w[i]%m + w[i-1]%m + 1 + m + m) % m;
        dp[i] = (dp[i] + s[i-1] + w[i]) % m;
        s[i] = (s[i-1] + dp[i]) % m;
        for(int j = i+i; j <= n; j += i) {
            w[j] += dp[i] - dp[i-1];
        }
    }
    cout << dp[n] << endl;
    return 0;
}