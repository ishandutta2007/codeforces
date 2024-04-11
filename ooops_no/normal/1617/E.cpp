#include<bits/stdc++.h>

using namespace std;

#define pb emplace_back
#define ld long double

mt19937 rnd(51);

unordered_map<int,int> ind;
unordered_map<int, vector<int>> g;
int val = -1;
pair<int,int> ans;

pair<int,int> dfs(int v, int p){
    pair<int,int> bst{-1e9, 0};
    if (ind[v] != 0){
        bst = {0, ind[v]};
    }
    sort(g[v].begin(), g[v].end());
    g[v].erase(unique(g[v].begin(), g[v].end()), g[v].end());
    for (auto to : g[v]){
        if (to != p){
            pair<int,int> p = dfs(to, v);
            p.first++;
            if (bst.first + p.first > val){
                ans.first = bst.second, ans.second = p.second;
                val = bst.first + p.first;
            }
            bst = max(bst, p);
        }
    }
    return bst;
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
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ind[a[i]] = i + 1;
        int v = a[i];
        while(__builtin_popcount(v) > 1){
            int j = 31 - (int)(__builtin_clz(v)) + 1;
            g[(1LL << j) - v].pb(v);
            v = (1LL << j) - v;
        }
        if (v > 0)
            g[0].pb(v);
    }
    dfs(0, -1);
    cout << ans.first << ' ' << ans.second << ' ' << val << endl;
    return 0;
}