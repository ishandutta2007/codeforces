#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll __int128

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5 + 10;
set<int> g[N];
vector<int> fb(N, 1);
vector<int> sz(N);
map<int,int> mp;

void zhfs(int v, int p){
    sz[v] = 1;
    for (auto to : g[v]){
        if (to != p){
            zhfs(to, v);
            sz[v] += sz[to];
        }
    }
}

pair<int,int> dfs(int v, int p, int szz){
    for (auto to : g[v]){
        if (to != p){
            if (mp[sz[to]] && mp[szz - sz[to]]){
                return {to, v};
            }
            pair<int,int> p = dfs(to, v, szz);
            if (p.first != 0) return p;
        }
    }
    return {0, 0};
}

bool solve(int v){
    zhfs(v, -1);
    if (sz[v] == 1) return 1;
    else{
        pair<int,int> p = dfs(v, -1, sz[v]);
        if (p.first == 0){
            return 0;
        }
        else{
            g[p.first].erase(p.second);
            g[p.second].erase(p.first);
            return (solve(p.first) && solve(p.second));
        }
    }
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].insert(b);
        g[b].insert(a);
    }
    mp[1] = 1;
    for (int i = 2; i < 40; i++){
        fb[i] = fb[i - 1] + fb[i - 2];
        mp[fb[i]] = 1;
    }
    if (mp[n] && solve(1)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    return 0;
}