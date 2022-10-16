#include <bits/stdc++.h>
using namespace std;

int dp[501][501][501],nxt[501],inf = 1001001001;

int main() {
    int n,m;
    string s,t;
    cin >> n >> m >> s >> t;
    for(int i = 0; i < 501; i++) {
        for(int j = 0; j < 501; j++) {
            for(int k = 0; k < 501; k++) {
                dp[i][j][k] = inf;
            }
        }
    }
    for(int i = 0; i <= m; i++) {
        string r = t.substr(0,i);
        if(i != m && t[i] == '0') {
            r += '1';
        }
        else if(i != m) {
            r += '0';
        }
        for(int j = r.size()-1; j >= 0; j--) {
            if(t.substr(0,j) == r.substr(r.size()-j,j)) {
                nxt[i] = j;
                break;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            for(int k = 0; k < m; k++) {
                if(k+1 == m) {
                    dp[i+1][j+1][nxt[k+1]] = min(dp[i+1][j+1][nxt[k+1]],dp[i][j][k]+(s[i] != t[k]));
                }
                else {
                    dp[i+1][j][k+1] = min(dp[i+1][j][k+1],dp[i][j][k]+(s[i] != t[k]));
                }
                dp[i+1][j][nxt[k]] = min(dp[i+1][j][nxt[k]],dp[i][j][k]+(s[i] == t[k]));
            }
        }
    }
    for(int i = 0; i+m-2 < n; i++) {
        int ans = inf;
        for(int k = 0; k < m; k++) {
            ans = min(ans,dp[n][i][k]);
        }
        cout << ((ans == inf)?-1:ans) << ((i+m-1 == n)?"\n":" ");
    }
}