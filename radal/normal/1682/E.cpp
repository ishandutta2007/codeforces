#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
//#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 4e5+20,mod = 1e9+7,inf = 1e9+10,base = 271;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k,int p){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%p;
        a = 1ll*a*a%p;
        k >>= 1;
    } 
    return z; 
}
vector<pll> adj[N];
vector<int> out[N];
int din[N],p[N],id[N];
bool cmp(pll x,pll y){
    return id[x.X] < id[y.X];
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,1,n+1) cin >> p[i];
    rep(i,1,n+1){
        int t = 1;
        int cur = i;
        while (!id[cur]){
            id[cur] = t;
            t++;
            cur = p[cur];
        }
    }
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb({v,i+1});
        adj[v].pb({u,i+1});
    }
    rep(i,1,n+1){
        sort(all(adj[i]),cmp);
        int po = -1,sz = adj[i].size();
        rep(j,0,sz){
            pll p = adj[i][j];
            if (id[i] < id[p.X]){
                po = j;
                break;
            }
        }
        if (po == -1){
            rep(j,0,sz-1){
                out[adj[i][j].Y].pb(adj[i][j+1].Y);
                din[adj[i][j+1].Y]++;
            }
            continue;
        }
        vector<pll> ve;
        rep(j,po,sz) ve.pb(adj[i][j]);
        rep(j,0,po) ve.pb(adj[i][j]);
        adj[i] = ve;
        rep(j,0,sz-1){
            out[ve[j].Y].pb(ve[j+1].Y);
            din[ve[j+1].Y]++;
        }
    }
    vector<int> ve,ans;
    rep(i,1,m+1){
        if (!din[i])
            ve.pb(i);
    }
    while(!ve.empty()){
        int v = ve.back();
        ve.pop_back();
        ans.pb(v);
        for (int u : out[v]){
            din[u]--;
            if (!din[u]) ve.pb(u);
        }
    }
    for (int u : ans) cout << u << ' ';
    return 0;
}