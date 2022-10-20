#include <bits/stdc++.h>
#define Task "D"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 2020, MOD = 1000000007;

int n, d;
long long res = 0;
int val[N], tr[N];
long long dp[N];
vector <int> a[N];
bool can[N][N];

void DFS(int u, int root, int par) {
    dp[u] = 1;
    for(int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if(!can[root][v] && val[v] >= val[root] && val[v] - val[root] <= d && v != par) {
            DFS(v, root, u);
            dp[u] = (dp[u] * (dp[v] + 1)) % MOD;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> d >> n;
    for(int i = 1; i <= n; i++) cin >> val[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j < i; j++)
            if(val[i] == val[j]) can[i][j] = 1;
    for(int i = 1; i <= n; i++) {
        DFS(i, i, 0);
        res = (res + dp[i]) % MOD;
    }
    cout << res;
    return 0;
}