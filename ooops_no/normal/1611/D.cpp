#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ld long double
#define pb push_back
#define ll long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> g[N];
vector<int> ind(N);
bool f = 0;

void zhfs(int v, int p, int mx){
    if (ind[v] < mx){
        f = 1;
    }
    mx = max(mx, ind[v]);
    for (auto to : g[v]){
        if (to != p){
            zhfs(to, v, mx);
        }
    }
}

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        g[i].clear();
    }
    vector<int> p(n), val(n), ans(n);
    int r = -1;
    for (int i = 0; i < n; i++){
        cin >> p[i];
        p[i]--;
        if (i == p[i]){
            r = i;
        }
        else{
            g[p[i]].pb(i);
        }
    }
    vector<int> per(n);
    for (int i = 0; i < n; i++){
        cin >> per[i];
        per[i]--;
        ind[per[i]] = i;
    }
    f = 0;
    zhfs(r, -1, -1);
    if (f){
        cout << -1 << endl;
        return;
    }
    int mx = -1;
    for (auto to : per){
        val[to] = val[p[to]];
        ans[to] = mx + 1 - val[to];
        val[to] = mx + 1;
        mx = val[to];
    }
    for (auto to : ans){
        cout << to << ' ';
    }
    cout << endl;
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