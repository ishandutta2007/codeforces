#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,avx2")
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
constexpr ll N = 5e2+10,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k,int md = mod){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%md;
        a = 1ll*a*a%md;
        k /= 2;
    } 
    return z; 
}
int d[N][N];
ld vis[N];
ld bst[N];
vector<int> adj[N];

inline void bfs(int r){
    d[r][r] = 0;
    queue<int> q;
    q.push(r);
    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : adj[v]) if (d[r][u] > d[r][v]+1){
            d[r][u] = d[r][v]+1;
            q.push(u);
        }
    }
}

int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    memset(d,63,sizeof d);
    int n,m;
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    rep(i,1,n+1) bfs(i);
    ld ans = 0.0;
    rep(i,1,n+1){
        ld calc = 0.0;
        rep(di,0,n){
            rep(j,0,n+1){
                vis[j] = 0;
            }
            int good = 0;
            vector<int> moj;
            rep(j,1,n+1){
                if (d[i][j] != di) continue;
                good++;
                for (int u : adj[j]){
                    if (!vis[u])
                        moj.pb(u);
                    vis[u] += 1.0/adj[j].size()/n;
                }
            }
            if (!good) break;
            ld mx = 1.0/n;
            if (good == 1){
                calc += mx;
                continue;
            }
            rep(j,1,n+1){
                ld sum = 0;
                for (int u : moj){
                    if (vis[u] <= bst[d[j][u]]) continue;
                    sum -= bst[d[j][u]];
                    sum += vis[u];
                    bst[d[j][u]] = vis[u];
                }
                mx = max(mx,(ld)sum);
                for (int u : moj) bst[d[j][u]] = 0;
            }
            calc += mx;
        }
        ans = max(ans,calc);
    }
    cout << setprecision(7) << fixed << ans;
    return 0;
}