#include<bits/stdc++.h>

#define int long long
#define pb push_back
#define ld long double

using namespace std;

mt19937 rnd(51);

const int N = 1e6 + 10;
map<string, int> mp;
set<int> st[N];
vector<int> g[N];
vector<int> cl(N);
vector<int> gr[N];
vector<bool> used(N);
vector<int> ans;

void dfs(int v){
    cl[v] = 1;
    for (auto to : g[v]){
        if (cl[to] == 0){
            dfs(to);
        }
        else if (cl[to] == 1){
            cout << "NO";
            exit(0);
        }
    }
    cl[v] = 2;
}

void zhfs(int v){
    used[v] = 1;
    for (auto to : g[v]){
        if (!used[to]){
            zhfs(to);
        }
    }
    ans.pb(v);
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        mp[s] = i + 1;
        v.pb(s);
    }
    for (int q = 0; q < m; q++){
        string t;
        int mt;
        cin >> t >> mt;
        int need = -1;
        vector<int> a;
        for (int i = 0; i < (1 << k); i++){
            string nw = t;
            for (int j = 0; j < k; j++){
                if (i & (1 << j)){
                    nw[j] = '_';
                }
            }
            if (mp[nw] == 0) continue;
            if (mp[nw] == mt){
                need = mp[nw];
            }
            else{
                a.pb(mp[nw]);
            }
        }
        if (need == -1){
            cout << "NO";
            return 0;
        }
        for (auto to : a){
            g[need].pb(to);
            gr[to].pb(need);
        }
    }
    for (int i = 0; i < N; i++){
        if (cl[i] == 0){
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++){
        if (gr[i].size() == 0 && !used[i]){
            zhfs(i);
        }
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n";
    for (auto to : ans) cout << to << " ";
    return 0;
}