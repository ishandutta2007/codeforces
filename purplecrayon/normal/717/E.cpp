#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n; vector<int> col;
vector<vector<int>> adj;
vector<int> cnt;
vector<int> path;

void init(int v, int p){
    cnt[v] = (col[v]==0);
    for(auto u : adj[v])
        if(u!=p) init(u, v), cnt[v] += cnt[u];
}

void dfs(int v, int p){
    path.push_back(v);
    for(auto u : adj[v])
        if(u!=p && cnt[v]){
            col[u] ^= 1;
            dfs(u, v);
            col[v] ^= 1;
            path.push_back(v);
        }
    if(!col[v]){
        if(v==0){
            int ch = adj[v].front();
            path.push_back(ch);
            path.push_back(v);
            path.push_back(ch);
            col[v] ^= 1;
        } else{
            path.push_back(p);
            path.push_back(v);
            col[p] ^= 1;
            col[v] ^= 1;
        }
    }
}

int main(){
    // freopen("a.in", "r", stdin);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    col.resize(n);
    cnt.resize(n);
    adj.resize(n);
    for(int i = 0; i<n; ++i){
        int x; cin >> x;
        col[i] = (x==1?1:0);
    }
    for(int i = 0; i<n-1; ++i){
        int u, v; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init(0, -1);
    dfs(0, -1);
    for(auto x : path)
        cout << x+1 << ' ';
    cout << '\n';
}