#include <bits/stdc++.h>
#define ll long long


using namespace std;

const int MAXN = (int) 200;

int dp[MAXN + 1][26 * MAXN + 1];


ll v[MAXN + 1];

int pow2[MAXN + 1], pow5[MAXN + 1];

inline int get(ll x, int d) {
    int cnt = 0;
    while(x % d == 0) {
        x /= d;
        cnt++;
    }
    return cnt;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, k, p5;
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int s2 = 0, s5 = 0;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        pow2[i] = get(v[i], 2);
        pow5[i] = get(v[i], 5);
        s2 += pow2[i];
        s5 += pow5[i];
    }
    for(i = 0; i <= k; i++)
        for(j = 0; j <= s5; j++)
           dp[i][j] = -(1 << 30);
    dp[0][0] = 0;
    for(i = 1; i <= n; i++) {
        for(j = k; j >= 1; j--)
           for(p5 = pow5[i]; p5 <= s5; p5++)
              dp[j][p5] = max(dp[j][p5], dp[j - 1][p5 - pow5[i]] + pow2[i]);
    }
    int ans = 0;
    for(p5 = 0; p5 <= s5; p5++)
        ans = max(ans, min(p5, dp[k][p5]));
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}