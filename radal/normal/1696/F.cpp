#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr int N = 1e2+20,mod = 1e9+7,inf = 1e9+10;
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
        k >>= 1;
    } 
    return z; 
}
vector<int> ve[N][N],adj[N];
vector<pll> ans;
int par[N][8],h[N],n,col[N],cnt[2],ed[N][N],lc[N][N];
bitset<N> di[N][N];
int lca(int u,int v){
    if (h[u] > h[v]) swap(u,v);
    repr(i,7,0){
        if (h[v]-h[u] >= (1 << i))
            v = par[v][i];
    }
    if (v == u) return v;
    repr(i,7,0){
        if (par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[v][0];
}
int dis(int u,int v){
    int w = lc[u][v];
    return h[u]+h[v]-2*h[w];
}
inline bool check2(){
    rep(j,1,8){
        rep(i,1,n+1){
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    rep(i,1,n+1){
        rep(j,1,n+1)
            lc[i][j] = lca(i,j);
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            int d = dis(i,j);
            rep(k,1,n+1){
                if (k == j) continue;
                int d2 = dis(i,k);
                if ((d == d2 && !di[i][j][k]) || (d != d2 && di[i][j][k])){
                    return 0;
                }
            }
        }
    }
    return 1;
}
bool dfs(int v,bool f){
    col[v] = f;
    cnt[f]++;
    for (int u : adj[v]){
        if (col[u] == f) return 0;
        if (col[u] == -1 && !dfs(u,!f)) return 0;
    }
    return 1;
}
bool check(int i,int j){
    ans.pb({i,j});
    par[j][0] = i;
    h[j] = h[i]+1;
    for (int k : ve[j][i]){
        if (k == i || par[k][0] == j || par[j][0] == k){
            continue;
        }
        if (par[k][0]){
            return 0;
        }
        if (!check(j,k)) return 0;
    }
    for (int k : ve[i][j]){
        if (k == j || par[k][0] == i || par[i][0] == k) continue;
        if (par[k][0])
            return 0;
        if (!check(i,k)) return 0;
    }
    return 1;
}
inline void solve(){
    cin >> n;
    rep(i,1,n+1){
        rep(j,1,n+1)
            di[i][j].reset();
    }
    cnt[0] = 0;
    cnt[1] = 0;
    rep(i,1,n+1){
        rep(j,1,n+1){
            ve[i][j].clear();
            ed[i][j] = 0;
        }
        col[i] = -1;
        adj[i].clear();
    }
    int e = 0;
    rep(i,1,n){
        rep(j,1,n-i+1){
            string s;
            cin >> s;
            rep(k,1,n+1){
                if (s[k-1] == '1'){
                    ve[k][i].pb(i+j);
                    ve[k][i+j].pb(i);
                    ed[i][i+j] = 1;
                    di[k][i][i+j] = 1;
                    di[k][i+j][i] = 1;
                }
            }
        }
    }
    rep(i,1,n){
        if (!ve[i][i].empty()){
            cout << "NO" << endl;
            return;
        }
        rep(j,i+1,n+1){
            if (!ed[i][j]){
                adj[i].pb(j);
                adj[j].pb(i);
                e++;
            }
        }
    }
    if (!dfs(1,0) || cnt[0]*cnt[1] != e || !e){
        cout << "No" << endl;
        return;
    }
    rep(i,1,n){
        rep(j,i+1,n+1){
            if (col[i] == col[j]) continue;
            par[i][0] = i;
            h[i] = 0;
            if (check(i,j) && (int)ans.size() == n-1 && check2()){
                cout << "YES" << endl;
                for (pll p : ans) cout << p.X << ' ' << p.Y << endl;
                ans.clear();
                rep(k,1,n+1) rep(g,0,8) par[k][g] = 0;
                return;
            }
            ans.clear();
            rep(k,1,n+1) rep(g,0,8) par[k][g] = 0;
        }
        break;
    }
    cout << "NO" << endl;
}
int main(){
   ios :: sync_with_stdio(0); cin.tie(0);
   int T = 1;
   cin >> T;
   while (T--){
       solve();
   }
}