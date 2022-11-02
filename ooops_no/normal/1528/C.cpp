#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3e5 + 10;
vector<int> gs[N], gk[N], tin(N), tout(N), t(10 * N), add(10 * N);
int cnt = 0, anss = 0;
int n;

void push(int v){
    t[v] += add[v];
    if (v * 2 < add.size()){
        add[v * 2] += add[v];
        add[v * 2 + 1] += add[v];
    }
    add[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val){
    push(v);
    if (l > r) return;
    if (tl == l && tr == r){
        add[v] += val;
        push(v);
        return;
    }
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), val), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r){
    push(v);
    if (l > r) return -1e18;
    if (tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void dfs(int v, int p = -1){
    tin[v] = cnt++;
    for (auto to : gk[v]){
        if (to != p){
            dfs(to, v);
        }
    }
    tout[v] = cnt++;
}

bool is_parent(int a, int b){
    return tin[a] <= tin[b] && tout[b] <= tout[a];
}

void zhfs(int v, int p, int ans){
    int val = get(1, 0, 2 * n - 1, tin[v], tout[v]);
    if (val == 0){
        ans++;
        update(1, 0, 2 * n - 1, tin[v], tout[v], v);
    }
    else if (is_parent(val, v)){
        update(1, 0, 2 * n - 1, tin[val], tout[val], -val);
        update(1, 0, 2 * n - 1, tin[v], tout[v], v);
    }
    anss = max(anss, ans);
    for (auto to : gs[v]){
        if (to != p){
            zhfs(to, v, ans);
        }
    }
    if (val == 0){
        ans--;
        update(1, 0, 2 * n - 1, tin[v], tout[v], -v);
    }
    else if (is_parent(val, v)){
        update(1, 0, 2 * n - 1, tin[val], tout[val], val);
        update(1, 0, 2 * n - 1, tin[v], tout[v], -v);
    }
}

void solve(){
    cin >> n;
    anss = 0, cnt = 0;
    for (int i = 0; i < 10 * n; i++){
        t[i] = add[i] = 0;
    }
    for (int i = 1; i <= n; i++){
        gs[i].clear();
        gk[i].clear();
        tin[i] = tout[i] = 0;
    }
    for (int i = 2; i <= n; i++){
        int a;
        cin >> a;
        gs[i].pb(a);
        gs[a].pb(i);
    }
    for (int i = 2; i <= n; i++){
        int a;
        cin >> a;
        gk[i].pb(a);
        gk[a].pb(i);
    }
    dfs(1);
    zhfs(1, -1, 0);
    cout << anss << endl;
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