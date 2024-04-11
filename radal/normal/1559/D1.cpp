#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<int,int> pll;
const long long int N=1e3+20,mod = 1e9+7,inf=8e18;
vector<int> adj1[N],adj2[N];
bool e[N][N];
int a[N],b[N],par[N][2],c[N],d[N];
int t;
bool vis[N];
void dfs2(int v){
    vis[v] = 1;
    b[v] = t;
    for (int u : adj1[v]) if (!vis[u]) dfs2(u);
}
void dfs(int v){
    vis[v] = 1;
    a[v] = t;
    for (int u : adj2[v]) if (!vis[u]) dfs(u);
}
int getpar(int v,bool f){
    if (par[v][f] == v) return v;
    return par[v][f] = getpar(par[v][f],f);
}
inline bool mg(int u,int v,bool f){
    u = getpar(u,f);
    v = getpar(v,f);
    if (u == v) return 0;

    return 1;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
   // cin >> T;
    while (T--){
        memset(e,1,sizeof e);
        int n,m1,m2;
        cin >> n >> m1 >> m2;
        rep(i,0,m1){
            int u,v;
            cin >> u >> v;
            adj1[u].pb(v);
            adj1[v].pb(u);
        }
        rep(i,0,m2){
            int u,v;
            cin >> u >> v;
            adj2[u].pb(v);
            adj2[v].pb(u);
        }
        rep(i,1,n+1){
            if (!vis[i]){
                t++;
                dfs(i);
            }
            vis[i] = 0;
        }
        t = 0;
        rep(i,1,n+1){
            if (!vis[i]){
                t++;
                dfs2(i);
            }
        }
        if (m1 > m2){
            cout << n-m1-1 << endl;
            rep(i,1,n+1){
                e[i][i] = 0;
                par[b[i]][1] = b[i];
                par[a[i]][0] = a[i];
            }
            rep(i,1,n+1){
                for (int u : adj2[i]){
                    e[i][u] = 0;
                    e[u][i] = 0;
                }
            }
            rep(i,1,n){
                rep(j,i+1,n+1){
                    if (e[i][j] && mg(b[i],b[j],1) && mg(a[i],a[j],0)){
                        par[getpar(b[i],1)][1] = getpar(b[j],1);
                        par[getpar(a[i],0)][0] = getpar(a[j],0);
                        cout << i << ' ' << j << endl;
                    }
                }
            }
            continue;
        }
        cout << n-m2-1 << endl;
        rep(i,1,n+1){
            e[i][i] = 0;
            par[a[i]][0] = a[i];
            par[b[i]][1] = b[i];
        }
        rep(i,1,n+1){
            for (int u : adj1[i]){
                e[i][u] = 0;
                e[u][i] = 0;
            }
        }
        rep(i,1,n){
            rep(j,i+1,n+1){
                if (e[i][j] && mg(a[i],a[j],0) && mg(b[i],b[j],1)){
                    par[getpar(a[i],0)][0] = getpar(a[j],0);
                    par[getpar(b[i],1)][1] = getpar(b[j],1);
                    cout << i << ' ' << j << endl;
                }
            }
        }
    }
    return 0;
}