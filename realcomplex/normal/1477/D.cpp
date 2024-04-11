#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 100;
set<int> T[N];
bool ban[N];
int xi[N];
int yi[N];

set<int> nodes;
vector<int> G[N];

void dfs(int u){
    vector<int> bq;
    for(auto x : nodes){
        if(!T[u].count(x)){
            G[u].push_back(x);
            G[x].push_back(u);
            bq.push_back(x);
        }
    }
    for(auto x : bq)
        nodes.erase(x);
    for(auto x : bq)
        dfs(x);
}

vector<int> L[N];
int typ[N];
int k = 0;

void cut(int node, int pp){
    vector<int> c[2];
    for(auto x : G[node]){
        if(x==pp) continue;
        cut(x,node);
        c[typ[x]].push_back(x);
    }
    if(!c[0].empty()){
        for(auto q : c[0]){
            L[node].push_back(q);
        }
        typ[node]=1;
    }
    else{
        if(pp == -1){
            L[c[1][0]].push_back(node);
        }
        typ[node]=0;
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    int u, v;
    k = 0;
    for(int i = 1; i <= n; i ++ ){
        T[i].clear();
        G[i].clear();
        ban[i]=false;
        L[i].clear();
    }
    nodes.clear();
    for(int i = 1; i <= m ; i ++ ){
        cin >> u >> v;
        T[u].insert(v);
        T[v].insert(u);
    }
    set<pii> ord;
    for(int i = 1; i <= n; i ++ ){
        ord.insert(mp((int)T[i].size(), i));
    }
    int id;
    int deg;
    while(!ord.empty()){
        auto it = ord.end();
        -- it;
        id = it->se;
        deg = it->fi;
        if(deg == (int)ord.size() - 1){
            xi[id]=ord.size();
            yi[id]=ord.size();
            ord.erase(it);
            ban[id]=true;
            for(auto x : T[id]){
                ord.erase(mp((int)T[x].size(), x));
                T[x].erase(id);
                ord.insert(mp((int)T[x].size(), x));
            }
            T[id].clear();
        }
        else{
            break;
        }
    }
    for(auto q : ord){
        nodes.insert(q.se);
    }
    vector<int> otx;
    while(!nodes.empty()){
        auto it = nodes.begin();
        nodes.erase(it);
        dfs(*it);
        otx.push_back(*it);
    }
    for(auto root : otx){
        cut(root, -1);
    }
    for(int i = 1; i <= n; i ++ ){
        if(!L[i].empty()){
            vector<int> ff;
            for(int j = 0; j <= L[i].size(); j ++ ){
                k++;
                ff.push_back(k);
            }
            xi[i]=ff[0];
            yi[i]=ff[L[i].size()];
            for(int j = 0; j < L[i].size(); j ++ ){
                xi[L[i][j]]=ff[j+1];
                yi[L[i][j]]=ff[j];
            }

        }
    }
    for(int i = 1; i <= n; i ++ ){
        cout << xi[i] << " ";
    }
    cout << "\n";
    for(int i = 1; i <= n; i ++ ){
        cout << yi[i] << " ";
    }
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve();
    return 0;
}