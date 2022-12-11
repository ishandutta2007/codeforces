#pragma GCC optimize("Ofast")
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
int subt[N];
ll total;

void dfs(int u, int pr){
    subt[u]=1;
    for(auto x : T[u]){
        if(x == pr) continue;
        
        dfs(x, u);
        subt[u]+=subt[x];
    }
}

void add(int a, int x){
    subt[a] += x;   
    total += x;
}

ll res = 0;
int n;
void dfs2(int u, int pr){
    res = max(res, total);
    int p1, p2;
    for(auto x : T[u]){
        if(x == pr)
            continue;;
        p1 = subt[u];
        p2 = subt[x];
        add(x, p1-p2);
        add(u, -p2);
        dfs2(x, u);
        add(u, p1 - subt[u]);
        add(x, p2 - subt[x]);
    }
}

int main(){
    fastIO;
    cin >> n;
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1, -1);
    for(int i = 1; i <= n; i ++ ){
        total += subt[i];
    }
    dfs2(1, -1);
    cout << res << "\n";
    return 0;
}