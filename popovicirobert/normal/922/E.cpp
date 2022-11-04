#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 175
// 44

using namespace std;

const int MAXN = 1000;
const int MAXC = (int) 1e4;

int birds[MAXN + 1], cst[MAXN + 1];

ll dp[2][MAXC + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ll w, b, x;
    ios::sync_with_stdio(false);
    cin >> n >> w >> b >> x;
    for(i = 1; i <= n; i++) {
        cin >> birds[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> cst[i];
    }
    memset(dp[1], -1, sizeof(dp[1]));
    dp[1][0] = w;
    for(i = 1; i <= birds[1]; i++) {
        dp[1][i] = max(-1LL, dp[1][i - 1] - cst[1]);
    }
    int sumc = birds[1];
    for(i = 2; i <= n; i++) {
        memset(dp[i & 1], -1, sizeof(dp[i & 1]));
        sumc += birds[i];
        for(j = 0; j <= sumc; j++) {
            dp[i & 1][j] = -1;
            for(int nr = 0; nr <= min(birds[i], j); nr++) {
                if(dp[1 - i & 1][j - nr] >= 0)
                    dp[i & 1][j] = max(dp[i & 1][j], min(dp[1 - i & 1][j - nr] + x, w + 1LL * b * (j - nr)) - 1LL * cst[i] * nr);
            }
        }
    }
    int ans = 0;
    for(i = 0; i <= sumc; i++) {
        if(dp[n & 1][i] >= 0)
            ans = i;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}