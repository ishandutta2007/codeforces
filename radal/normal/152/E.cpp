#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr int N = 2e2+20,mod = 1e9+7,inf = 1e9+10;
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
vector<vector<int>> dp[N],a,mi[N],mark;
vector<vector<vector<pair<int,pll> > > > adj[N];
short int ja[N][N][N];
bool vis[N][N];
void dfs(int i,int x,int y){
    if (!i) return;
    vis[x][y] = 1;
    for (auto p : adj[i][x][y]){
        dfs(p.X,p.Y.X,p.Y.Y);
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    a.resize(n);
    mark.resize(n);
    rep(i,0,n){
        a[i].resize(m);
        mark[i].resize(m);
        rep(j,0,m){
            mark[i][j] = -1;
            cin >> a[i][j];
        }
    }
    pll cur = {-1,-1};
    rep(i,0,k){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        cur = {x,y};
        mark[x][y] = i;
    }
    int g = (1 << k);
    dp[0].resize(n);
    mi[0].resize(n);
    adj[0].resize(n);
    rep(i,0,n){
        dp[0][i].resize(m);
        mi[0][i].resize(m);
        adj[0][i].resize(m);
    }
    int ans = inf;
    rep(i,1,g){
        dp[i].resize(n);
        mi[i].resize(n);
        adj[i].resize(n);
        priority_queue<pair<int,pll>> pq;
        rep(x,0,n){
            dp[i][x].resize(m);
            mi[i][x].resize(m);
            adj[i][x].resize(m);
            rep(y,0,m){
                dp[i][x][y] = inf;
                mi[i][x][y] = inf;
                if (mark[x][y] != -1 && (i&(1 << mark[x][y]))){
                    int v = i^(1 << mark[x][y]);
                    if (!v)
                        dp[i][x][y] = a[x][y];
                    for(int j = v; j > 0; j = (j-1)&v){
                        int cal = dp[j][x][y]+mi[(v^j)][x][y];
                        if (dp[i][x][y] > cal){
                            dp[i][x][y] = cal;
                            adj[i][x][y].clear();
                            adj[i][x][y].pb({j,{x,y}});
                            if (!(v^j)) continue;
                            int d = ja[v^j][x][y];
                            if (d == 1) adj[i][x][y].pb({v^j,{x-1,y}});
                            else if (d == 2) adj[i][x][y].pb({v^j,{x,y+1}});
                            else if (d == 3) adj[i][x][y].pb({v^j,{x+1,y}});
                            else adj[i][x][y].pb({v^j,{x,y-1}});
                        }
                    }

                }
                else{
                    for(int j = ((i-1)&i); j > 0; j = (j-1)&i){
                        int cal = dp[j][x][y]+mi[(i^j)][x][y];
                        if (dp[i][x][y] > cal){
                            dp[i][x][y] = cal;
                            adj[i][x][y].clear();
                            adj[i][x][y].pb({j,{x,y}});
                            int d = ja[i^j][x][y];
                            if (d == 1) adj[i][x][y].pb({i^j,{x-1,y}});
                            else if (d == 2) adj[i][x][y].pb({i^j,{x,y+1}});
                            else if (d == 3) adj[i][x][y].pb({i^j,{x+1,y}});
                            else adj[i][x][y].pb({i^j,{x,y-1}});
                        }
                    }
                }
                pq.push({-dp[i][x][y],{x,y}});
                if (i == g-1) ans = min(ans,dp[i][x][y]);
            }
        }
        while (!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int x = p.Y.X,y = p.Y.Y;
            if (dp[i][x][y] != -p.X) continue;
            if (x && dp[i][x-1][y] > dp[i][x][y]+a[x-1][y]){
                dp[i][x-1][y] = dp[i][x][y] + a[x-1][y];
                adj[i][x-1][y].clear();
                adj[i][x-1][y].pb({i,{x,y}});
                pq.push({-dp[i][x-1][y],{x-1,y}});
            }
            if (y && dp[i][x][y-1] > dp[i][x][y]+a[x][y-1]){
                dp[i][x][y-1] = dp[i][x][y] + a[x][y-1];
                adj[i][x][y-1].clear();
                adj[i][x][y-1].pb({i,{x,y}});
                pq.push({-dp[i][x][y-1],{x,y-1}});
            }
            if (x+1 < n && dp[i][x+1][y] > dp[i][x][y]+a[x+1][y]){
                dp[i][x+1][y] = dp[i][x][y] + a[x+1][y];
                adj[i][x+1][y].clear();
                adj[i][x+1][y].pb({i,{x,y}});
                pq.push({-dp[i][x+1][y],{x+1,y}});
            }
            if (y+1 < m && dp[i][x][y+1] > dp[i][x][y]+a[x][y+1]){
                dp[i][x][y+1] = dp[i][x][y] + a[x][y+1];
                adj[i][x][y+1].clear();
                adj[i][x][y+1].pb({i,{x,y}});
                pq.push({-dp[i][x][y+1],{x,y+1}});
            }
        }
        rep(x,0,n){
            rep(y,0,m){
                int mn = inf;
                if (x) mn = min(mn,dp[i][x-1][y]);
                if (y) mn = min(mn,dp[i][x][y-1]);
                if (x+1 < n) mn = min(mn,dp[i][x+1][y]);
                if (y+1 < m) mn = min(mn,dp[i][x][y+1]);
                mi[i][x][y] = mn;
                if (x && mn == dp[i][x-1][y]) ja[i][x][y] = 1;
                if (y+1 < m && mn == dp[i][x][y+1]) ja[i][x][y] = 2;
                if (x+1 < n && mn == dp[i][x+1][y]) ja[i][x][y] = 3;
                if (y && mn == dp[i][x][y-1]) ja[i][x][y] = 4;
            }
        }
    }
    cout << ans << endl;
    dfs(g-1,cur.X,cur.Y);
    rep(i,0,n){
        rep(j,0,m){
            if (vis[i][j])
                cout << 'X';
            else cout << '.';
        }
        cout << endl;
    }
    return 0;
}