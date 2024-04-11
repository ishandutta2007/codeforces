#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e3 + 10;
const int inf = 1e9+10;
const int MOD = 1e9 + 7;
int dp[maxn][maxn], C[maxn][maxn];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double n;
    double p;
    cin >> n >> p;
    for(int i = 0; i <= n; i++) {
        double q = (i * (i-1) * (i-2) / 6) / (n * (n-1) * (n-2) / 6);
        q += (i * (i-1) / 2 * (n-i)) / (n * (n-1) * (n-2) / 6);
        q += (i * (n-i) * (n-i-1) / 2) / (n * (n-1) * (n-2) / 6) * 0.5;
        if(q >= p-1e-6) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}