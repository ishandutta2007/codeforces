#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

int n, l, s;
const int N = 1e5 + 10;
vector<int> g[N], d(N), sum(N), w(N), go(N), dp(N);
int po[20][N];

void dfs(int v, int p){
    for (auto to : g[v]){
        if (to != p){
            d[to] = d[v] + 1;
            po[0][to] = v;
            dfs(to, v);
        }
    }
}

void zhfs(int v, int p){
    sum[v] += w[v];
    if (sum[v] <= s && d[v] + 1 <= l){
        go[v] = 1;
    }
    else{
        int q = v;
        for (int i = 19; i >= 0; i--){
            int u = po[i][q];
            if (u == 1) continue;
            u = po[0][u];
            if (d[v] - d[u] <= l && sum[v] - sum[u] <= s){
                q = po[i][q];
            }
        }
        go[v] = q;
    }
    for (auto to : g[v]){
        if (to != p){
            sum[to] = sum[v];
            zhfs(to, v);
        }
    }
}

void walk(int v, int p){
    int mn = -1;
    for (auto to : g[v]){
        if (to != p){
            walk(to, v);
            dp[v] += dp[to];
            if (mn == -1 || d[go[to]] < d[mn]){
                mn = go[to];
            }
        }
    }
    if (mn == -1){
        dp[v] = 1;
        return;
    }
    if (d[mn] > d[v]){
        dp[v]++;
    }
    else{
        go[v] = mn;
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> l >> s;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
        if (w[i] > s){
            cout << -1;
            return 0;
        }
    }
    for (int i = 2; i <= n; i++){
        int a;
        cin >> a;
        g[i].pb(a);
        g[a].pb(i);
    }
    po[0][1] = 1;
    dfs(1, -1);
    for (int i = 1; i < 20; i++){
        for (int j = 1; j <= n; j++){
            po[i][j] = po[i - 1][po[i - 1][j]];
        }
    }
    zhfs(1, -1);
    walk(1, -1);
    cout << dp[1] << endl;
    return 0;
}