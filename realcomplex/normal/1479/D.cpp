#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)3e5 + 100;
const int T = (int)1e7;

vector<int> E[N];
int n;
int A[N];
ll X[N];
int root[N];

struct node{
    ll val;
    int lef;
    int rig;
};

node Q[T];

int cnt;

int get_val(int node, int cl, int cr, int pos){
    if(node == -1) return 0;
    if(cl == cr){
        return Q[node].val;
    }
    int mid = (cl + cr) / 2;
    if(mid >= pos)
        return get_val(Q[node].lef, cl, mid, pos);
    else
        return get_val(Q[node].rig, mid + 1, cr, pos);

}

int update(int node, int cl, int cr, int pos, ll vv){
    cnt ++ ;
    int id = cnt;
    if(node == -1){
        Q[id] = {0,-1,-1};
    }
    else{
        Q[id] = Q[node];
    }
    Q[id].val ^= vv;
    if(cl == cr){
        return id;
    }
    int mid = (cl + cr) / 2;
    if(mid >= pos){
        int lf = update(Q[id].lef, cl, mid, pos, vv);
        Q[id].lef = lf;
    }
    else{
        int rf = update(Q[id].rig, mid + 1, cr, pos, vv);
        Q[id].rig = rf;
    }
    return id;
}

const int LOG = 20;
int tin[N];
int tout[N];
int it;
int up[LOG][N];

void dfs(int u, int par){
    if(par == 0) up[0][u]=1;
    else up[0][u]=par;
    for(int i = 1; i < LOG; i ++) {
        up[i][u]=up[i-1][up[i-1][u]];
    }
    it ++ ;
    tin[u] = it;
    root[u] = update(root[par], 1, n, A[u], X[A[u]]);
    for(auto x : E[u]){
        if(x == par) continue;
        dfs(x, u);
    }
    tout[u] = it;
}

bool is_anc(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int get_lca(int u, int v){
    if(is_anc(u,v)) return u;
    if(is_anc(v,u)) return v;
    for(int i = LOG - 1; i >= 0; i -- ){
        if(!is_anc(up[i][u], v))
            u = up[i][u];
    }
    return up[0][u];
}

// f(u,li,ri) xor f(v,li,ri) xor (X[lca] : 0 ? A[lca] >= li && ri >= A[lca])

int go(int node, int dir){
    if(node == -1) return -1;
    if(dir == 0) return Q[node].lef;
    else return Q[node].rig;
}

int get(int lef_n, int rig_n, int li, int ri, int tl, int tr, int lca){
    if(ri < tl || li > tr) return -1;
    ll cur = 0;
    if(lef_n != -1) cur ^= Q[lef_n].val;
    if(rig_n != -1) cur ^= Q[rig_n].val;
    if(A[lca] >= li && A[lca] <= ri){
        cur ^= X[A[lca]];
    }
    if(cur == 0) return -1;
    if(li >= tl && ri <= tr){
        if(li == ri) return li;
        int mid = (li + ri) / 2;
        int clf = get(go(lef_n,0),go(rig_n,0),li,mid,tl,tr,lca);
        if(clf != -1) return clf;
        clf = get(go(lef_n,1),go(rig_n,1),mid+1,ri,tl,tr,lca);
        return clf;
    }
    else{
        int mid = (li + ri) / 2;
        int clf = get(go(lef_n,0), go(rig_n,0),li,mid,tl,tr,lca);
        int crf = get(go(lef_n,1), go(rig_n,1),mid+1,ri,tl,tr,lca);
        if(clf == -1 && crf == -1)
            return -1;
        if(clf == -1) return crf;
        return clf;
    }


}

int main(){
    fastIO;
    Q[0] = {0,-1,-1};
    cnt = 0;
    int q;
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    for(int i = 1; i <= n; i ++ ){
        X[i] = (((ll)rng() % (ll)1e18) + (ll)1e18) % (ll)1e18;
    }
    int u, v;
    for(int i = 1; i < n; i ++ ){
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(1,0);
    int ui, vi, li, ri;
    for(int i = 1; i <= q; i ++ ){
        cin >> ui >> vi >> li >> ri;
        cout << get(root[ui], root[vi], 1, n, li, ri, get_lca(ui,vi)) << "\n";
    }
    return 0;
}