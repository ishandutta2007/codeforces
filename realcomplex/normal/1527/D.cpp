#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
const int LOG = 19;
vector<int> T[N];
int up[LOG][N];
int tin[N];
int tout[N];
int cc;

bool is_anc(int a, int b){
    if(tin[a] <= tin[b] && tout[a] >= tout[b]) return true;
    return false;
}

int subt[N];
int dep[N];

void dfs(int u, int pp){
    cc ++ ;
    tin[u] = cc;
    up[0][u] = pp;
    subt[u] = 1;
    for(int i = 1; i < LOG; i ++ ){
        up[i][u] = up[i - 1][up[i - 1][u]];
    }
    for(auto x : T[u]){
        if(x != pp){
            dep[x] = dep[u] + 1;
            dfs(x, u);
            subt[u] += subt[x];
        }
    }
    tout[u] = cc;
}

ll outp[N];

int lca(int u, int v){
    if(is_anc(u, v)) return u;
    if(is_anc(v, u)) return v;
    for(int lg = LOG - 1; lg >= 0 ; lg -- ){
        if(!is_anc(up[lg][u], v))
            u = up[lg][u];
    }
    return up[0][u];
}

int get(int u, int v){
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}

void solve(){
    int n;
    cin >> n;
    cc = 0;
    for(int i = 0 ; i < n; i ++ ){
        T[i].clear();
    }
    for(int i = 0 ; i <= n + 1; i ++ )
        outp[i] = 0;
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        T[u].push_back(v);
        T[v].push_back(u);
    }
    dfs(0, 0);
    outp[0] = n * 1ll * (n - 1) / 2ll;
    outp[1] = outp[0];
    for(auto x : T[0]){
        outp[1] -= subt[x] * 1ll * (subt[x] - 1) / 2ll;
    }

    int lef = 0, rig = 0;
    int go;
    for(int add = 1; add < n; add ++ ){
        if(get(lef, add) + get(add, rig) == get(lef, rig)){

        }
        else if(get(add, lef) + get(lef, rig) == get(add, rig)){
            lef = add;
        }
        else if(get(add, rig) + get(rig, lef) == get(add, lef)){
            rig = add;
        }
        else{
            break;
        }
        if(is_anc(lef,rig)){
            swap(lef, rig);
        }
        if(is_anc(rig,lef)){
            go = lef;
            for(int lg = LOG - 1; lg >= 0; lg -- ){
                if(is_anc(up[lg][go], rig)) continue;
                go = up[lg][go];
            }
            outp[add + 1] = subt[lef] * 1ll * (n - subt[go]);
        }
        else{
            outp[add + 1] = (subt[lef] * 1ll * subt[rig]);
        }
    }
    for(int i = 0 ; i <= n; i ++ ){
        cout << outp[i] - outp[i + 1] << " ";
    }
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}