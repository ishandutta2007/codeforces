#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb emplace_back
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> g[N];
vector<int> dp(N);
int ans = 1e18, n;

void dfs(int v, int p){
    vector<int> a;
    for (auto to : g[v]){
        if (to != p){
            dfs(to, v);
            a.pb(dp[to]);
        }
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a.size() > 0 && *min_element(a.begin(), a.end()) == -1){
        dp[v] = -1;
        return;
    }
    if (p == -1){
        if (a.size() == 0){
            dp[v] = 0;
            return;
        }
        if (a.size() > 2){
            dp[v] = -1;
            return;
        }
        dp[v] = a[0] + a.back();
        return;
    }
    if (a.size() > 1){
        dp[v] = -1;
    }
    else{
        dp[v] = (a.size() > 0 ? a[0] + 1 : 1);
    }
}

vector<int> bfs(int v){
    vector<int> d(n, 1e18), par(n, -1);
    d[v] = 0;
    deque<int> q{v};
    while(q.size() > 0){
        int u = q.front();
        q.pop_front();
        for (auto to : g[u]){
            if (d[to] == 1e18){
                d[to] = d[u] + 1;
                par[to] = u;
                q.pb(to);
            }
        }
    }
    int u = 0, mx;
    for (int i = 0; i < n; i++){
        if (d[i] > d[u]){
            u = i;
        }
    }
    vector<int> a;
    a.pb(u);
    mx = d[u];
    while(u != v){
        if (abs(d[u] - mx / 2) < 3){
            a.pb(u);
        }
        u = par[u];
    }
    return a;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    int v = bfs(0)[0];
    auto arr = bfs(v);
    for (auto v : arr){
        dfs(v, -1);
        while(dp[v] % 2 == 0) dp[v] /= 2;
        if (dp[v] != -1){
            ans = min(ans, dp[v]);
        }
    }
    cout << (ans == 1e18 ? -1 : ans) << endl;
    return 0;
}