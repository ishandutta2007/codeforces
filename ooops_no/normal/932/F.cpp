#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10;
vector<int> aa(N), b(N), sz(N), g[N];
vector<pair<ld, ld>> d[N];
vector<int> ans(N);

ld func(pair<ld, ld> a, pair<ld, ld> b){
    return (ld)(b.second - a.second) / (ld)(a.first - b.first);
}

void add(int i, ld a, ld b){
    while(d[i].size() >= 2 && func(d[i].back(), {a, b}) <= func(d[i][d[i].size() - 2], d[i].back())){
        d[i].pop_back();
    }
    d[i].pb({a, b});
}

void dfs(int v, int p){
    ans[v] = 1e18;
    vector<pair<ld, ld>> a;
    for (auto to : g[v]){
        if (to != p){
            dfs(to, v);
            for (auto t : d[to]){
                a.pb(t);
                ans[v] = min(ans[v], (int)(t.first * aa[v] + t.second));
            }
        }
    }
    if (a.size() == 0){
        ans[v] = 0;
        add(v, b[v], ans[v]);
        return;
    }
    a.pb({b[v], ans[v]});
    sort(a.rbegin(), a.rend());
    for (auto to : a){
        add(v, to.first, to.second);
    }
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> aa[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}