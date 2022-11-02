#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 2e5 + 10;
set<pair<int,int>> g[N];
set<int> a;
bool used[N][2];

void dfs(int v, int i){
    used[v][i] = 1;
    a.insert(v);
    for (auto to : g[v]){
        if (!used[to.first][(to.second + i) % 2]){
            dfs(to.first, (to.second + i) % 2);
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
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) g[i].clear();
        for (int i = 0; i < n; i++){
            used[i][1] = used[i][0] = 0;
        }
        for (int i = 0; i < m; i++){
            int a, b;
            cin >> a >> b;
            a--, b--;
            string s;
            cin >> s;
            if (s == "imposter"){
                g[a].insert({b, 1});
                g[b].insert({a, 1});
            }
            else{
                g[a].insert({b, 0});
                g[b].insert({a, 0});
            }
        }
        bool x = 0;
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (!used[i][0] && !used[i][1]){
                a.clear();
                dfs(i, 0);
                vector<int> cnt(2);
                for (auto to : a){
                    if (used[to][0] && used[to][1]){
                        x = 1;
                    }
                    cnt[0] += used[to][0];
                    cnt[1] += used[to][1];
                }
                ans += max(cnt[0], cnt[1]);
            }
        }
        cout << (x ? -1 : ans) << endl;
    }
    return 0;
}