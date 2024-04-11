#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int M = (int)1e6 + 10;
const int LOG = 19;
bool act[M];
int u[M], v[M];
int num[M];

int par[M];
int cnt;

int fin(int u){
    if(par[u] == u) return u;
    return par[u]=fin(par[u]);
}

vector<pii> G[M];

void unite(int a, int b, int x){
    a=fin(a);
    b=fin(b);
    if(a==b) return;
    cnt++;
    G[cnt].push_back({a, x});
    G[cnt].push_back({b, x});
    par[a]=cnt;
    par[b]=cnt;
}

bool vis[M];
int pp[LOG][M];
int low[LOG][M];
int tin[M], tout[M];
int tit;

void dfs(int u, int pi, int hh){
    tin[u]=tit++;
    vis[u]=true;
    pp[0][u] = pi;
    low[0][u] = hh;
    for(int i = 1; i < LOG; i ++ ){
        pp[i][u]=pp[i-1][pp[i-1][u]];
        low[i][u]=min(low[i-1][u], low[i-1][pp[i-1][u]]);
    }
    for(auto nx : G[u]){
        dfs(nx.fi, u, nx.se);
    }
    tout[u]=tit-1;
}

pii segt[M * 2];
void setid(int x, pii y){
    x += tit;
    segt[x]=y;
    x /= 2;
    while(x > 0){
        segt[x] = max(segt[x * 2], segt[x * 2 + 1]);
        x /= 2;
    }
}

pii get(int cl, int cr){
    cl += tit;
    cr += tit;
    pii sol = mp(0,0);
    while(cl <= cr){
        if(cl % 2 == 1) sol = max(sol, segt[cl ++ ]);
        if(cr % 2 == 0) sol = max(sol, segt[cr -- ]);
        cl /= 2;
        cr /= 2;
    }
    return sol;
}

int main(){
    fastIO;
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i < M; i ++ ){
        par[i]=i;
    }
    cnt=n;
    for(int i = 1; i <= n; i ++ )
        cin >> num[i];
    for(int i = 1; i <= m ; i ++ ){
        cin >> u[i] >> v[i];
        act[i]=true;
    }
    vector<pii> qq;
    int typ, id;
    for(int i = 1; i <= q; i ++ ){
        cin >> typ >> id;
        qq.push_back({typ, id});
        if(typ == 2)
            act[id]=false;
    }
    for(int i = 1; i <= m ; i ++ ){
        if(act[i]){
            unite(u[i], v[i], q + 1);
        }
    }
    for(int i = q - 1; i >= 0 ; i -- ){
        if(qq[i].fi == 2){
            unite(u[qq[i].se], v[qq[i].se], i+1);
        }
    }
    for(int i = cnt; i >= 1; i -- ){
        if(!vis[i])
            dfs(i, i, (int)1e9);
    }
    for(int i = 1; i <= n; i ++ ){
        setid(tin[i],{num[i], tin[i]});
    }
    int ver;
    for(int T = 1; T <= q; T ++ ){
        if(qq[T-1].fi == 2) continue;
        ver = qq[T-1].se;
        for(int j = LOG - 1; j >= 0 ; j -- ){
            if(T < low[j][ver])
                ver = pp[j][ver];
        }
        pii mx = get(tin[ver], tout[ver]);
        cout << mx.fi << "\n";
        setid(mx.se, {0, mx.se});
    }
    return 0;
}