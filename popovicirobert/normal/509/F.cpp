#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = 500;

int dp[MAXN + 1][MAXN + 1], aux[MAXN + 1][MAXN + 1];
int ord[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> ord[i];
    }
    for(i = 1; i <= n; i++) {
        dp[i][i] = 1;
        aux[i][i] = 1;
    }
    for(int len = 1; len < n; len++) {
        for(int l = 1; l + len <= n; l++) {
            int r = l + len;
            for(i = r - 1; i > l; i--) {
                if(ord[i] < ord[r]) {
                    aux[l + 1][r] = (aux[l + 1][r] + 1LL * dp[i][r - 1] * aux[l + 1][i]) % MOD;
                }
            }
            for(i = l + 1; i <= r; i++) {
                dp[l][r] = (dp[l][r] + 1LL * dp[i][r] * aux[l + 1][i]) % MOD;
            }
        }
    }
    cout << dp[1][n];
    //cin.close();
    //cout.close();
    return 0;
}