#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
vector<int> T[N];
int subt[N];
int ord[N];
int id[N];
int ci;

void dfs(int u, int pp){
    subt[u]=1;
    ord[ci]=u;
    id[u]=ci;
    ci++;
    for(auto x : T[u]){
        if(x == pp) continue;
        dfs(x, u);
        subt[u] += subt[x];
    }
}


int main(){
    fastIO;
    int n;
    cin >> n;
    int u, v;
    for(int i = 1; i < n;i  ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(1,-1);
    int root = 1, par = -1;
    bool mov = true;
    while(mov){
        mov = false;
        for(auto x : T[root]){
            if(x == par) continue;
            if(subt[x] > n/2){
                par = root;
                root = x;
                mov = true;
                break;
            }
        }
    }
    ci=0;
    dfs(root,-1);
    ll soln = 0;
    for(int i = 1; i <= n; i ++ ){
        if(i==root) continue;
        soln += 2ll * subt[i];
    }
    cout << soln << " ";
    cout << "\n";
    int mx = (n+1)/2;
    for(int i = 1; i <= n; i ++ ){
        cout << ord[(id[i]+mx)%n] << " ";
    }
    cout << "\n";
    return 0;
}