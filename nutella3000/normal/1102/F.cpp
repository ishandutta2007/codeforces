#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;
typedef vector<int> vi;
int main() {
    //freopen('","r",stdin);
    //freopen("","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0 ;i < n;i++) {
        for(int j = 0;j < m;j++) {
            cin >> a[i][j];
        }
    }
    int gr[n][n];
    int dp[n][1 << n][n];
    int from_to[n][n];
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            gr[i][j] = 1000000000;
            from_to[i][j] = 1000000000;
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            for(int u = 0;u < (1 << n);u++) {
                dp[i][u][j] = 0;
            }
            for(int k = 0;k < m;k++) {
                gr[i][j] = min(gr[i][j],abs(a[i][k] - a[j][k]));
                if (k > 0) from_to[i][j] = min(from_to[i][j],abs(a[i][k - 1] - a[j][k]));
            }
        }
    }
    for(int i = 0;i < n;i++) {
        dp[i][1 << i][i] = 1000000000;
    }
    for(int mask = 2;mask < (1 << n);mask++) {
        for(int from = 0;from < n;from++) {
            if ((mask & (1 << from)) > 0) {
                for(int to = 0;to < n;to++) {
                    if (to != from && (mask & (1 << to)) > 0) {
                        int mx = 0;
                        for(int i = 0;i < n;i++) {
                            if (i != from && (mask & (1 << i)) > 0) mx = max(mx,min(gr[from][i],dp[i][mask - (1 << from)][to]));
                        }
                        dp[from][mask][to] = mx;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if (i != j || n == 1) ans = max(ans,min(dp[i][(1 << n) - 1][j],from_to[i][j]));
        }
    }
    cout << ans;
 }