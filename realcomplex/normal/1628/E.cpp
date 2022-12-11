#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

struct edge{
    int uu;
    int vv;
    int ww;
    bool operator< (const edge &E) const {
        return ww < E.ww;
    }
};

const int N = (int)3e5 + 10;

int par[N];

int fin(int x){
    if(par[x] == x) return x;
    return par[x]=fin(par[x]);
}

int id[N];

const int M = N * 2;
const int LOG = 20;
int tin[M];
int tout[M];
int up[LOG][M];
int weight[M];

vector<int> T[M];

int ti;

void dfs(int u){
    ti ++ ;
    tin[u]=ti;
    for(auto x : T[u]){
        dfs(x);
    }
    tout[u]=ti;
}

struct node{
    int lazy;
    int low;
    int maxi;
    int low1;
    int maxi1;
};

node TR[N * 4 + 512];

void build(int node, int cl, int cr){
    TR[node] = {0, (int)1e9, 0, (int)1e9, 0};
    if(cl == cr){
       TR[node].low1 = tin[cl];
       TR[node].maxi1 = tout[cl];
       return;
    }
    int mid = (cl + cr) / 2;
    build(node * 2, cl, mid);
    build(node * 2 + 1, mid + 1, cr);
    TR[node].low1=min(TR[node*2].low1,TR[node*2+1].low1);
    TR[node].maxi1=max(TR[node*2].maxi1,TR[node*2+1].maxi1);
}

void push(int node, int cl, int cr){
    if(TR[node].lazy == 0) return;
    if(TR[node].lazy == -1){
        TR[node].low=(int)1e9;
        TR[node].maxi=0;
    }
    if(TR[node].lazy == +1){
        TR[node].low=TR[node].low1;
        TR[node].maxi=TR[node].maxi1;
    }
    if(cl != cr){
        TR[node*2].lazy=TR[node].lazy;
        TR[node*2+1].lazy=TR[node].lazy;
    }
    TR[node].lazy = 0;
}

void upd(int node, int cl, int cr, int tl, int tr, int type){
    push(node, cl, cr);
    if(cr < tl || cl > tr) return;
    if(cl >= tl && cr <= tr){
        TR[node].lazy = type;
        push(node, cl, cr);
        return;
    }
    int mid = (cl + cr) / 2;
    upd(node * 2, cl, mid, tl, tr, type);
    upd(node * 2 + 1, mid + 1, cr, tl, tr, type);
    TR[node].low=min(TR[node*2].low,TR[node*2+1].low);
    TR[node].maxi=max(TR[node*2].maxi,TR[node*2+1].maxi);
}

int main(){
    fastIO;
    int n, q;
    cin >> n >> q;
    vector<edge> lis;
    int u, v, w;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v >> w;
        lis.push_back({u, v, w});
    }
    sort(lis.begin(), lis.end());
    for(int i = 1; i <= n; i ++ ){
        par[i] = i;
        id[i] = i;
        weight[i] = -1;
    }
    for(int lg = 0 ; lg < LOG; lg ++ ){
        for(int i = 1; i <= 2 * n - 1; i ++ ){
            up[lg][i] = -1;
        }
    }
    int cnt = n;
    for(auto x : lis){
        u = x.uu;
        v = x.vv;
        w = x.ww;
        u = fin(u);
        v = fin(v);

        cnt ++ ;
        T[cnt].push_back(id[u]);
        T[cnt].push_back(id[v]);
        up[0][id[u]]=cnt;
        up[0][id[v]]=cnt;
        weight[cnt] = x.ww;

        par[u]=v;
        id[v]=cnt;
    }
    for(int lg = 1; lg < LOG; lg ++ ){
        for(int i = 1; i <= cnt; i ++ ){
            if(up[lg-1][i] == -1) continue;
            up[lg][i]=up[lg-1][up[lg-1][i]];
        }
    }
    dfs(cnt);
    build(1, 1, n);
    int typ, lef, rig;
    int node;
    int ml;
    int mr;
    int nex;
    for(int iq = 1; iq <= q; iq ++ ){
        cin >> typ;
        if(typ == 1){
            cin >> lef >> rig;
            upd(1, 1, n, lef, rig, +1);
        }
        else if(typ == 2){
            cin >> lef >> rig;
            upd(1, 1, n, lef, rig, -1);
        }
        else{
            cin >> node;
            ml = tin[node];
            mr = tout[node];
            ml = min(ml, TR[1].low);
            mr = max(mr, TR[1].maxi);
            for(int lg = LOG - 1; lg >= 0 ; lg -- ){
                if(up[lg][node] == -1) continue;
                nex = up[lg][node];
                if(tin[nex] > ml || tout[nex] < mr){
                    node = nex;
                }
            }
            if(tin[node] > ml || tout[node] < mr)
                node = up[0][node];
            cout << weight[node] << "\n";
        }
    }
    return 0;
}