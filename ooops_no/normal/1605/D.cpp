#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long

mt19937 rnd(51);

const int N = 2e5 + 10;
vector<int> g[N], all[2];

void dfs(int v, int p, int now){
    all[now].pb(v - 1);
    for (auto to : g[v]){
        if (to != p){
            dfs(to, v, now ^ 1);
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
        int n;
        cin >> n;
        vector<int> ans(n, -1);
        set<int> st;
        for (int i = 1; i <= n; i++){
            g[i].clear();
            st.insert(i);
        }
        for (int i = 0; i < n - 1; i++){
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            g[b].pb(a);
        }
        all[0].clear(), all[1].clear();
        dfs(1, -1, 0);
        if (all[0].size() > all[1].size()) swap(all[0], all[1]);
        for (int i = 19; i >= 0; i--){
            if ((1 << i) <= all[0].size()){
                for (int j = 0; j < (1 << i); j++){
                    ans[all[0].back()] = (1 << i) + j;
                    st.erase((1 << i) + j);
                    all[0].pop_back();
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (ans[i] == -1){
                ans[i] = *st.begin();
                st.erase(st.begin());
            }
        }
        for (auto to : ans) cout << to << ' ';
        cout << endl;
    }
    return 0;
}