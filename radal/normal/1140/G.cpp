#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 3e5+10,mod = 998244353,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k /= 2;
    } 
    return z; 
}
int par[N][20],h[N],sz[N],tin[N],T;
ll sp[N][20][2][2],seg[N*4];
ll d[N][2],sw[N],lst[N][2];
vector<pair<int,ll> > adj[N][2];
vector<int> ti;
void dfs(int v,int p,bool f){
    par[v][0] = p;
    sz[v] = 1;
    if (!f){
        tin[v] = T;
        T++;
        ti.pb(v);
    }
    for (pair<int,ll> u : adj[v][f]){
        if (u.X == p) continue;
        h[u.X] = h[v]+1;
        d[u.X][f] = d[v][f]+u.Y;
        lst[u.X][f] = u.Y;
        dfs(u.X,v,f);
        sz[v] += sz[u.X];
    }
}
void build(int l,int r,int v = 1){
    if (r-l == 1){
        seg[v] = d[ti[l]][0]+d[ti[l]][1]+sw[ti[l]];
        return;
    }
    int u = (v << 1),m = (l+r) >> 1;
    build(l,m,u);
    build(m,r,u|1);
    seg[v] = min(seg[u],seg[u|1]);
}

ll que(int l,int r,int s,int e,int v = 1){
    if (s <= l && r <= e) return seg[v];
    if (s >= r || l >= e) return 1ll*inf*inf;
    int m = (l+r) >> 1,u = (v << 1);
    return min(que(l,m,s,e,u),que(m,r,s,e,u|1));
}

inline int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,19,0){
        if ((h[v]-h[u]) >= (1 << i)){
            v = par[v][i];
        }
    }
    if (u == v) return u;
    repr(i,19,0){
        if (par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[v][0];
}

bool cmp(int u,int v){
    return h[u] < h[v];
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    rep(i,1,n+1) cin >> sw[i];
    rep(i,1,n){
        int u,v;
        ll w1,w2;
        cin >> u >> v >> w1 >> w2;
        adj[u][0].pb({v,w1});
        adj[u][1].pb({v,w2});
        adj[v][0].pb({u,w1});
        adj[v][1].pb({u,w2});
    }
    dfs(1,0,0);
    dfs(1,0,1);
    rep(j,1,20)
        rep(i,2,n+1)
            par[i][j] = par[par[i][j-1]][j-1];
    build(0,n);
    vector<int> vh;
    rep(i,1,n+1){
        sw[i] = que(0,n,tin[i],tin[i]+sz[i])-d[i][0]-d[i][1];
        vh.pb(i);
    }
    sort(all(vh),cmp);
    rep(i,1,n){
        int v = vh[i];
        sw[v] = min(sw[v],sw[par[v][0]]+lst[v][1]+lst[v][0]);
    }
    build(0,n);
    rep(i,2,n+1){
        ll mi = que(0,n,tin[i],tin[i]+sz[i]);
        int p = par[i][0];
        sp[i][0][0][0] = min(lst[i][0],mi-d[i][0]-d[p][1]+sw[p]);
        sp[i][0][0][1] = min(lst[i][0]+sw[p],mi-d[i][0]-d[p][1]);
        sp[i][0][1][0] = min(lst[i][1]+sw[p],mi-d[i][1]-d[p][0]);
        sp[i][0][1][1] = min(lst[i][1],mi-d[i][1]-d[p][0]+sw[p]);
    }
    rep(j,1,20){
        rep(i,2,n+1){
            if (h[i] < (1 << j)) continue;
            rep(x,0,2){
                rep(y,0,2){
                    sp[i][j][x][y] = 1ll*inf*inf;
                    rep(z,0,2){
                        sp[i][j][x][y] = min(sp[i][j][x][y],sp[i][j-1][x][z]+sp[par[i][j-1]][j-1][z][y]);
                    }
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--){
        int u,v;
        cin >> u >> v;
        bool f1 = 1,f2 = 1;
        if (u&1) f1 = 0;
        if (v&1) f2 = 0;
        u = (u+1)/2;
        v = (v+1)/2;
        if (u == v){
            cout << sw[u] << endl;
            continue;
        }
        int w = lca(u,v);
        vector<int> v1,v2;
        rep(i,0,20){
            if ((1 << i)&(h[v]-h[w])) v2.pb(i);
            if ((1 << i)&(h[u]-h[w])) v1.pb(i);
        }
        if (w != v && w != u){
            ll a[2][2],b[2][2],c[2][2];
            rep(i,0,2){
                rep(j,0,2){
                    a[i][j] = sp[u][v1[0]][i][j];
                    b[i][j] = sp[v][v2[0]][i][j];
                }
            }
            u = par[u][v1[0]];
            v = par[v][v2[0]];
            for(int j : v1){
                if (j == v1[0]) continue;
                rep(x,0,2){
                    rep(y,0,2){
                        c[x][y] = 1ll*inf*inf;
                        rep(z,0,2){
                            c[x][y] = min(c[x][y],a[x][z]+sp[u][j][z][y]);
                        }
                    }
                }
                rep(x,0,2) rep(y,0,2) a[x][y] = c[x][y];
                u = par[u][j];
            }

            for(int j : v2){
                if (j == v2[0]) continue;
                rep(x,0,2){
                    rep(y,0,2){
                        c[x][y] = 1ll*inf*inf;
                        rep(z,0,2){
                            c[x][y] = min(c[x][y],b[x][z]+sp[v][j][z][y]);
                        }
                    }
                }
                rep(x,0,2) rep(y,0,2) b[x][y] = c[x][y];
                v = par[v][j];
            }
            cout << min(a[f1][0]+b[f2][0],a[f1][1]+b[f2][1]) << endl;
            continue;
        }
        if (w == u){
            swap(u,v);
            swap(f1,f2);
            swap(v1,v2);
        }
        ll a[2][2],c[2][2];
        rep(i,0,2){
            rep(j,0,2){
                a[i][j] = sp[u][v1[0]][i][j];
            }
        }
        u = par[u][v1[0]];
        for(int j : v1){
            if (j == v1[0]) continue;
            rep(x,0,2){
                rep(y,0,2){
                    c[x][y] = 1ll*inf*inf;
                    rep(z,0,2){
                        c[x][y] = min(c[x][y],a[x][z]+sp[u][j][z][y]);
                    }
                }
            }
            rep(x,0,2) rep(y,0,2) a[x][y] = c[x][y];
            u = par[u][j];
        }
        cout << a[f1][f2] << endl;
    }
    return 0;
}