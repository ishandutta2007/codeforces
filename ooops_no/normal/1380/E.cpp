#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<pair<int, pair<int,int>>> st[N];
int par[N], ans = 0;
vector<bool> used(N);

int find_set(int v){
    if (v == par[v]) return v;
    else return par[v] = find_set(par[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (st[a].size() < st[b].size()) swap(a, b);
    par[b] = a;
    for (auto to : st[b]){
        if (used[to.second.second]) continue;
        if (find_set(to.first) == find_set(to.second.first)){
            used[to.second.second] = 1;
            ans--;
        }
        else{
            st[a].pb(to);
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
    for (int i = 0; i < N; i++){
        par[i] = i;
    }
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m);
    vector<int> type(n);
    for (int i = 0; i < n; i++){
        int j;
        cin >> j;
        a[j - 1].pb(i);
        type[i] = j - 1;
    }
    for (int i = 0; i + 1 < n; i++){
        if (type[i] != type[i + 1]){
            ans++;
            st[type[i]].pb({type[i], {type[i + 1], i}});
            st[type[i + 1]].pb({type[i], {type[i + 1], i}});
        }
    }
    for (int i = 0; i < m; i++){
        cout << ans << endl;
        if (i != m - 1){
            int u, v;
            cin >> u >> v;
            u--, v--;
            union_set(u, v);
        }
    }
    return 0;
}