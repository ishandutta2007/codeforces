#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)2e5 + 10;
int u[N], v[N];
int par[N];
int nex[N];
vector<int> lis[N];

int fin1(int u){
    if(nex[u] == u) return u;
    return nex[u]=fin1(nex[u]);
}

void unite1(int u, int v){
    u=fin1(u);
    v=fin1(v);
    if(u == v) return;
    nex[u]=v;
}

int fin(int u){
    if(par[u] == u) return u;
    return par[u]=fin(par[u]);
}

void check(int node){
    if(fin(node) == fin(node - 1)){
        unite1(node - 1, node);
    }
    if(fin(node) == fin(node + 1)){
        unite1(node, node + 1);
    }
}


void unite(int u, int v){
    u=fin(u);
    v=fin(v);
    if(u == v) return;
    if(lis[u].size() > lis[v].size()) swap(u, v);
    par[u]=v;
    for(auto x : lis[u]){
        check(x);
        lis[v].push_back(x);
    }
    lis[u].clear();
}


int lef[N];
int rig[N];
vector<int> cand[N];
int a[N];
int b[N];

void solve(){
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= m ; i ++ ){
        cin >> u[i] >> v[i];
    }
    for(int iq = 1; iq <= q; iq ++ ){
        lef[iq] = 0;
        rig[iq] = m;
        cin >> a[iq] >> b[iq];
    }
    bool ok = true;
    while(ok){
        ok = false;
        for(int i = 0; i <= n + 1; i ++ ){
            par[i] = nex[i] = i;
            lis[i].clear();
            if(1 <= i && i <= n) lis[i].push_back(i);
        }
        for(int i = 0 ; i <= m ; i ++ ){
            cand[i].clear();
        }
        for(int iq = 1; iq <= q; iq ++ ){
            if(lef[iq] < rig[iq]){
                ok = true;
                cand[(lef[iq] + rig[iq]) / 2].push_back(iq);
            }
        }
        for(int i = 0; i <= m; i ++ ){
            if(i){
                unite(u[i], v[i]);
            }
            for(auto x : cand[i]){

                if(fin1(a[x]) >= b[x]){
                    rig[x] = (lef[x] + rig[x]) / 2;
                }
                else{
                    lef[x] = (lef[x] + rig[x]) / 2 + 1;
                }
            }
        }
    }
    for(int i = 1; i <= q; i ++ ){
        cout << lef[i] << " ";
    }
    cout << "\n";

}

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}