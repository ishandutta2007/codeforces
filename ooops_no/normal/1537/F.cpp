#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> g[N];
vector<int> color(N), u(N), t(N);
bool x = 0;

void dfs(int v){
    for (auto to : g[v]){
        if (color[to] == color[v]){
            x = 1;
        }
        else if (color[to] == 0){
            if (color[v] == 1) color[to] = 2;
            else color[to] = 1;
            dfs(to);
        }
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    x = 0;
    for (int i = 1; i <= n; i++){
        g[i].clear();
        color[i] = 0;
    }
    for (int i = 1; i <= n; i++){
        cin >> u[i];
    }
    int mem = 0;
    for (int i = 1; i <= n; i++){
        cin >> t[i];
        mem += u[i] - t[i];
    }
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }
    mem = abs(mem);
    color[1] = 1;
    dfs(1);
    vector<int> sum(2);
    if (x && mem % 2 == 0){
        cout << "YES\n";
        return;
    }
    for (int i = 1; i <= n; i++){
        sum[color[i] - 1] += u[i] - t[i];
    }
    if (sum[0] == sum[1]){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}