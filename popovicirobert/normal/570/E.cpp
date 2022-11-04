#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 220
// 44

using namespace std;


const int MOD = (int) 1e9 + 7;
const int MAXN = 505;

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

char mat[MAXN + 1][MAXN + 1];
int dp[2][MAXN + 1][MAXN + 1];

char dl[] = {0, 1}, dc[] = {1, 0};

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> mat[i] + 1;
    }
    int sz = (n + m) / 2;
    dp[1][1][n] = (mat[1][1] == mat[n][m]);
    for(int len = 2; len <= sz; len++) {
        for(int l1 = 1; l1 <= len; l1++) {
            int c1 = len + 1 - l1;
            for(int lin = 1; lin <= len; lin++) {
                int l2 = n - lin + 1;
                int c2 = m - (len + 1 - lin) + 1;
                if(mat[l1][c1] == mat[l2][c2]) {
                    int cur = 0;
                    cur += dp[1 - len & 1][l1 - 1][l2];
                    mod(cur);
                    cur += dp[1 - len & 1][l1 - 1][l2 + 1];
                    mod(cur);
                    cur += dp[1 - len & 1][l1][l2];
                    mod(cur);
                    cur += dp[1 - len & 1][l1][l2 + 1];
                    mod(cur);
                    dp[len & 1][l1][l2] = cur;
                }
                else {
                    dp[len & 1][l1][l2] = 0;
                }
            }
        }
    }
    int ans = 0;
    if((n + m) % 2) {
        for(int l1 = 1; l1 <= sz; l1++) {
            int c1 = sz + 1 - l1;
            for(int p = 0; p < 2; p++) {
                int l2 = l1 + dl[p];
                int c2 = c1 + dc[p];
                if(l2 > 0 && l2 <= n && c2 > 0 && c2 <= m) {
                    ans += dp[sz & 1][l1][l2];
                    mod(ans);
                }
            }
        }
    }
    else {
        for(int l1 = 1; l1 <= sz; l1++) {
            int c1 = sz + 1 - l1;
            ans += dp[sz & 1][l1][l1];
            mod(ans);
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}