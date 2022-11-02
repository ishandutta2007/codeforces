#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 10;
set<int> g[N];
vector<int> d(N);
vector<int> tin(N), tout(N);
vector<int> lol, rem;
int cnt = 0, now = 0;

void zhfs(int v, int p){
    cnt++;
    for (auto to : g[v]){
        if (to != p){
            zhfs(to, v);
        }
    }
}

void gfs(int v, int p){
    if (v == 1) return;
    cnt++;
    for (auto to : g[v]){
        if (to != p){
            gfs(to, v);
        }
    }
}

void dfs(int v, int p){
    tin[v] = now++;
    d[v] = 1;
    for (auto to : g[v]){
        if (to != p){
            dfs(to, v);
            d[v] += d[to];
        }
    }
    tout[v] = now++;
}

void walk(int v, int p){
    lol.pb(v);
    if (v == 1){
        rem = lol;
    }
    for (auto to : g[v]){
        if (to != p){
            walk(to, v);
        }
    }
    lol.pop_back();
}

bool is_parent(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

void solve(){
    int n;
    cin >> n;
    lol.clear(), rem.clear();
    for (int i = 0; i <= n; i++) {
        g[i].clear();
        d[i] = 0;
        tin[i] = 0;
        tout[i] = 0;
    }
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    int anss = 0;
    vector<int> a;
    for (auto to : g[0]){
        cnt = 0;
        zhfs(to, 0);
        anss += cnt * (cnt - 1) / 2;
        cnt = 0;
        gfs(to, 0);
        a.pb(cnt);
    }
    cout << anss << " ";
    anss = 0;
    int sum = 0;
    for (auto to : a) sum += to;
    for (int i = 0; i < a.size(); i++){
        anss += (sum - a[i]) * a[i];
    }
    cout << anss / 2 + sum << " ";
    walk(0, -1);
    g[rem[0]].erase(rem[1]);
    g[rem[1]].erase(rem[0]);

    g[rem[0]].insert(n);
    g[n].insert(rem[0]);

    g[rem[1]].insert(n);
    g[n].insert(rem[1]);

    dfs(n, -1);
    int u = 0, v = 1;
    int mem = 1;
    for (int i = 2; i < n; i++){
        if (is_parent(i, u) || is_parent(i, v)){
            cout << 0 << " ";
            continue;
        }
        if (mem == 0){
            cout << mem << " ";
            continue;
        }
        if (is_parent(u, i)){
            cout << d[v] * (d[u] - d[i]) << " ";
            u = i;
        }
        else if (is_parent(v, i)){
            cout << d[u] * (d[v] - d[i]) << " ";
            v = i;
        }
        else{
            cout << d[v] * d[u] << " ";
            mem = 0;
        }
    }
    if (mem == 0){
        cout << 0 << ' ';
    }
    else{
        cout << d[v] * d[u] << ' ';
    }
    cout << endl;
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}