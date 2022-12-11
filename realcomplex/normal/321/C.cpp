#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)1e5 + 9;
bool use[N];
int dep[N];
vector<int> T[N];
int sbt[N];

void dfs(int u,int par){
    sbt[u] = 1;
    for(auto x : T[u]){
        if(use[x] || x == par) continue;
        dfs(x, u);
        sbt[u] += sbt[x];
    }
}

int find_centroid(int t){
    dfs(t,-1);
    int req = sbt[t] / 2;
    int node = t;
    int par = -1;
    bool ok = true;
    while(ok){
        ok = false;
        for(auto x : T[node]){
            if(use[x] || x == par)
                continue;
            if(sbt[x] > req){
                ok=true;
                par = node;
                node = x;
                break;
            }
        }
    }
    return node;
    
}

void decompose(int node, int dd){
    node=find_centroid(node);
    use[node] = true;
    dep[node] = dd;
    for(auto x : T[node]){
        if(!use[x]){
            decompose(x,dd+1);
        }
    }
}

int main(){
    fastIO;
    int n;
    cin >> n;
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
 
    decompose(1,0);
    for(int i = 1; i <= n ; i ++ ){
        cout << char(dep[i] + 'A') << " ";
    }
    return 0;
}