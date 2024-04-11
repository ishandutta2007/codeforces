#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 100;
vector<int> T[N];
int dep[N];
vector<int> lay[N];
int par[N];

void dfs(int u){
    lay[dep[u]+1].push_back(u);
    for(auto x : T[u]){
        if(dep[x] == -1){
            dep[x]=dep[u]+1;
            par[x]=u;
            dfs(x);
        }
    }
}

void solve(int id){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        T[i].clear();
        lay[i].clear();
        dep[i] = -1;
    }
    int u, v;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dep[1]=0;
    dfs(1);
    int node;
    for(int k = (n+1)/2; k <= n; k ++ ){
        if(lay[k].size() >= 1){
            node = lay[k][0];
            cout << "PATH\n";
            vector<int> sol;
            while(1){
                sol.push_back(node);
                if(node==1){
                    break;
                }
                node=par[node];
            }
            cout << sol.size() << "\n";
            for(auto x : sol) cout << x << " ";
            cout << "\n";
            return;
        }
        else{
            vector<pii> pari;
            for(int k = 0 ; k <= n; k ++ ){
                for(int i = 1; i < lay[k].size(); i += 2){
                    pari.push_back(mp(lay[k][i], lay[k][i-1]));
                }
            }
            cout << "PAIRING\n";
            cout << pari.size() << "\n";
            for(auto v : pari)
                cout << v.fi << " " << v.se << "\n";
            return;
        }
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve(t);
    return 0;
}