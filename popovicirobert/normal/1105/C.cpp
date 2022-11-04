#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;
const int MAXN = (int) 2e5;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline int get1(int x) {
    if(x < 1)
        return 0;
    return (x - 1) / 3 + 1;
}

inline int get2(int x) {
    if(x < 2)
        return 0;
    return (x - 2) / 3 + 1;
}

int dp[MAXN + 1][3];
int cnt[3];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, l, r;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> l >> r;
    cnt[0] = r / 3 - (l - 1) / 3;
    cnt[1] = get1(r) - get1(l - 1);
    cnt[2] = get2(r) - get2(l - 1);
    //cerr << cnt[0] << " " << get2(r) << " " << get2(l - 1) << "\n";
    dp[0][0] = 1;
    for(i = 1; i <= n; i++) {
        for(int a = 0; a < 3; a++) {
            for(int b = 0; b < 3; b++) {
                dp[i][(a + b) % 3] = (dp[i][(a + b) % 3] + 1LL * dp[i - 1][a] * cnt[b]) % MOD;
            }
        }
    }
    cout << dp[n][0];
    //cin.close();
    //cout.close();
    return 0;
}