#include <bits/stdc++.h>
#define MAXN 50
#define INF 10000000

using namespace std;

int dp[MAXN + 1][MAXN + 1][MAXN + 1];

inline int check(int n, int m, int k) {
    if(n * m == k || k == 0)
        return 0;
    if(n * m < k)
        return INF;
    if(dp[n][m][k] != -1)
        return dp[n][m][k];
    int i, j;
    dp[n][m][k] = INF;
    for(i = 1; i < n; i++)
        for(j = 0; j <= k; j++)
           dp[n][m][k] = min(dp[n][m][k], check(i, m, j) + check(n - i, m, k - j) + m * m);
    for(i = 1; i < m; i++)
        for(j = 0; j <= k; j++)
           dp[n][m][k] = min(dp[n][m][k], check(n, i, j) + check(n, m - i, k - j) + n * n);
    return dp[n][m][k];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, k, t;
    ios::sync_with_stdio(false);
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while(t > 0) {
        t--;
        cin >> n >> m >> k;
        cout << check(n, m, k) << endl;
    }
    //cin.close();
    //cout.close();
    return 0;
}