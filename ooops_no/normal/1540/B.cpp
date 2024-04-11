#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 250, MOD = 1e9 + 7;
int inv[N], dp[N][N], po[20][N], ans = 0, d[N];
vector<int> g[N];
int n;

int pow(int a, int n){
    if (n == 0) return 1;
    if (n % 2 == 0){
        int g = pow(a, n / 2);
        return (g * g % MOD);
    }
    else{
        return (pow(a, n - 1) * a % MOD);
    }
}

void dfs(int v, int p){
    for (auto to : g[v]){
        if (to != p){
            d[to] = d[v] + 1;
            po[0][to] = v;
            dfs(to, v);
        }
    }
}

int lca(int a, int b){
    if (d[a] < d[b]){
        swap(a, b);
    }
    for (int i = 19; i >= 0; i--){
        if (d[po[i][a]] >= d[b]){
            a = po[i][a];
        }
    }
    if (a == b) return a;
    for (int i = 19; i >= 0; i--){
        if (po[i][a] != po[i][b]){
            a = po[i][a], b = po[i][b];
        }
    }
    return po[0][a];
}

void solve(int v){
    d[v] = 0;
    po[0][v] = v;
    dfs(v, -1);
    for (int i = 1; i < 20; i++){
        for (int j = 1; j <= n; j++){
            po[i][j] = po[i - 1][po[i - 1][j]];
        }
    }
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            int g = lca(i, j);
            ans = (ans + dp[d[i] - d[g]][d[j] - d[g]]) % MOD;
        }
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < N; i++) inv[i] = pow(i, MOD - 2);
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (j == 0){
                dp[i][j] = 1;
            }
            else if (i == 0){
                dp[i][j] = 0;
            }
            else{
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * inv[2] % MOD;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        solve(i);
    }
    ans = (ans * inv[n]) % MOD;
    cout << ans << endl;
    return 0;
}