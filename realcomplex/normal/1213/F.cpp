#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 9;
vector<int> T[N];
vector<int> R[N];
vector<int> ord;
bool vis[N];

void dfs(int u){
    if(vis[u])
        return;
    vis[u]=true;
    for(auto x : T[u]){
        dfs(x);
    }
    ord.push_back(u);
}

int idx[N];
int col[N];
int cnt;

vector<int> G[N];

void dfs1(int u){
    if(idx[u] > 0) return;
    idx[u] = cnt;
    for(auto x : R[u]){
        dfs1(x);
    }
}

int deg[N];
int a[N];
int b[N];
int main(){
    fastIO;
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n ; i ++ ){
        cin >> a[i];
    }
    for(int i = 0 ; i < n ; i ++ ){
        cin >> b[i];
    }
    for(int i = 1 ; i < n ; i ++ ){
        T[a[i - 1]].push_back(a[i]);
        R[a[i]].push_back(a[i-1]);
    }
    for(int i = 1; i < n ; i ++ ){
        T[b[i-1]].push_back(b[i]);
        R[b[i]].push_back(b[i-1]);
    }
    for(int i = 1 ; i <= n ; i ++ )
        dfs(i);
    int node;
    while(!ord.empty()){
        node = ord.back();
        ord.pop_back();
        if(idx[node] > 0) continue;
        ++cnt;
        dfs1(node);
    }
    for(int i = 1 ; i < n; i ++ ){
        if(idx[a[i-1]] != idx[a[i]])
            G[idx[a[i-1]]].push_back(idx[a[i]]);
        if(idx[b[i-1]] != idx[b[i]])
            G[idx[b[i-1]]].push_back(idx[b[i]]);
    }
    for(int i = 1 ; i <= cnt ; i ++ ){
        for(auto x : G[i])
            deg[x] ++ ;
    }
    queue<int> ff;
    for(int i = 1; i <= cnt ; i ++ ){
        if(deg[i] == 0)
            ff.push(i);
    }
    int res;
    while(!ff.empty()){
        node = ff.front();
        ff.pop();
        res = max(res, col[node] + 1);
        for(auto x : G[node]){
            deg[x] -- ;
            col[x] = max(col[x], col[node] + 1);
            if(deg[x]==0)
                ff.push(x);
        }
    }
    if(res < k){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i ++ ){
        cout << char(min(col[idx[i]],25) + 'a');
    }
    cout << "\n";
    return 0;
}