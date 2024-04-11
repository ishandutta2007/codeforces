#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 100;
const int LOG = 20;
vector<int> T[N];

int tin[N];
int tout[N];
int par[LOG][N];
int ti;


void dfs(int u, int pi){
    ti ++ ;
    tin[u] = ti;
    par[0][u] = pi;
    for(int i = 1; i < LOG; i ++ )
        par[i][u] = par[i-1][par[i-1][u]];
    for(auto x : T[u]){
        if(x == pi) continue;
        dfs(x, u);
    }
    tout[u]=ti;
}

bool is_anc(int a, int b){
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int go_up(int a, int b){
    if(a == b) return -1;
    for(int i = LOG - 1; i >= 0 ; i -- ){
        if(!is_anc(par[i][a], b))
            a = par[i][a];
    }
    return a;
}

int lca(int a, int b){
    if(is_anc(a,b)) return a;
    for(int i = LOG - 1; i >= 0 ; i -- )
        if(!is_anc(par[i][a], b))
            a = par[i][a];
    return par[0][a];
}


vector<pii> E[N];
int cnt[N];
int Q[N];

ll sol = 0;

bool valid(pii a, pii b){
    if(a.fi != -1 && (b.fi == a.fi || b.se == a.fi)) return false;
    if(a.se != -1 && (b.fi == a.se || b.se == a.se)) return false;
    return true;
}

void dfs2(int u, int pp){
    for(auto x : T[u]){
        if(x == pp) continue;
        dfs2(x, u);
        cnt[u] += cnt[x];
        Q[u] += Q[x];
    }
    ll cur;
    for(auto x : E[u]){
        cur = cnt[u];
        if(x.fi != -1) cur -= Q[x.fi];
        if(x.se != -1) cur -= Q[x.se];
        sol += cur;
    }
    int m = E[u].size();
    ll bad = m * 1ll * (m - 1) / 2ll;
    map<int, int> cc;
    map<pii, int> pap;
    for(auto x : E[u]){
        if(x.fi > 0) cc[x.fi] ++ ;
        if(x.se > 0) cc[x.se] ++ ;
        if(x.fi > 0 && x.se > 0)
            pap[x] ++ ;
    }
    for(auto x : cc){
        bad -= (x.se * 1ll * (x.se - 1)) / 2ll;
    }
    for(auto x : pap){
        bad += (x.se * 1ll * (x.se - 1)) / 2ll;
    }
    sol += bad;
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
    dfs(1, 1);
    int m;
    cin >> m;
    int i1, i2;
    int lc;
    int pp;
    for(int q = 0; q < m; q ++ ){
        cin >> u >> v;
        lc = lca(u, v);
        i1 = go_up(u, lc);
        i2 = go_up(v, lc);
        cnt[u] ++ ;
        cnt[v] ++ ;
        cnt[lc] -= 2;
        if(i1 != -1){
            Q[u] ++ ;
            Q[i1] -- ;
        }
        if(i2 != -1){
            Q[v] ++ ;
            Q[i2] -- ;
        }
        if(i1 > i2) swap(i1, i2);
        E[lc].push_back(mp(i1, i2));
    }
    dfs2(1,1);
    cout << sol << "\n";
    return 0;
}