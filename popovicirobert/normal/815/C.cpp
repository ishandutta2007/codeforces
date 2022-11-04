#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = (int) 5e3;
const int INF = (ll) 1e16;

vector <int> g[MAXN + 1];

ll dp[2][MAXN + 1][MAXN + 1];
int pr[MAXN + 1], disc[MAXN + 1];
int sz[MAXN + 1];

int n;

void dfs(int nod) {
    int i, j;
    dp[1][nod][0] = INF;
    for(i = 2; i <= n; i++)
        dp[0][nod][i] = dp[1][nod][i] = INF;
    dp[0][nod][1] = pr[nod];
    dp[1][nod][1] = pr[nod] - disc[nod];
    sz[nod] = 1;
    for(auto it : g[nod]) {
        dfs(it);
        for(i = sz[nod]; i >= 0; i--)
            for(j = sz[it]; j >= 0; j--) {
                dp[0][nod][i + j] = min(dp[0][nod][i + j], dp[0][nod][i] + dp[0][it][j]);
                dp[1][nod][i + j] = min(dp[1][nod][i + j], dp[1][nod][i] + dp[1][it][j]);
            }
        sz[nod] += sz[it];
    }
    for(i = 1; i <= sz[nod]; i++)
        dp[1][nod][i] = min(dp[1][nod][i], dp[0][nod][i]);
}


int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i, x, b;
    ios::sync_with_stdio(false);
    cin >> n >> b;
    for(i = 1; i <= n; i++) {
        cin >> pr[i] >> disc[i];
        if(i > 1) {
            cin >> x;
            g[x].push_back(i);
        }
    }
    dfs(1);
    int ans = 1;
    while(ans <= n && dp[1][1][ans] <= b)
        ans++;
    cout << ans - 1;
    //cin.close();
    //cout.close();
    return 0;
}