#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MOD = 998244353;
const int MAXN = (int) 2e5;
const int MAXK = 100;

int arr[MAXN + 1];

int nxt[MAXN + 1][MAXK + 1];
int dp[MAXN + 1][MAXK + 1];
int sp[MAXN + 1];

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
    if(x < 0)
        x += MOD;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, k, len;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k >> len;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        for(j = 1; j <= k; j++) {
            if(arr[i - 1] != j && arr[i - 1] > -1) {
                nxt[i][j] = i - 1;
            }
            else {
                nxt[i][j] = nxt[i - 1][j];
            }
        }
    }
    sp[0] = 1;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= k; j++) {
            if(arr[i] > -1 && arr[i] != j) {
                continue;
            }
            dp[i][j] = sp[i - 1];
            if(i >= len && i - nxt[i][j] >= len) {
                dp[i][j] -= sp[i - len];
                mod(dp[i][j]);
                dp[i][j] += dp[i - len][j];
                mod(dp[i][j]);
            }
            sp[i] += dp[i][j];
            mod(sp[i]);
        }
    }
    int ans = 0;
    for(i = 1; i <= k; i++) {
        ans += dp[n][i];
        mod(ans);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}