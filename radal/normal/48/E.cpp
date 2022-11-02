#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=2e2+20,mod = 1e9+7,inf=1e12,maxq = 5e5+30,maxm = 3e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
ll h,t,r,n,m;
pll a[N],b[N];
ll d[N][N],dp[N][N];
int vis[N][N];
void bfs(){
    queue <pll> q;
    q.push({h,t});
    d[h][t] = 0;
    while (!q.empty()){
        pll p = q.front();
        q.pop();
        if (!p.X && !p.Y) return;
        ll m1 = min(m,p.Y);
        rep(i,1,m1+1){
            if (p.Y+b[i].X+b[i].Y-i+p.X  > r) continue;
            if (d[p.X+b[i].X][p.Y+b[i].Y-i] > d[p.X][p.Y]+1){
                d[p.X+b[i].X][p.Y+b[i].Y-i] = d[p.X][p.Y]+1;
                q.push({p.X+b[i].X,p.Y+b[i].Y-i});
            }
        }
        ll n1 = min(n,p.X);
        rep(i,1,n1+1){
            if (p.X+a[i].X+a[i].Y-i+p.Y  > r) continue;
            if (d[p.X+a[i].X-i][p.Y+a[i].Y] > d[p.X][p.Y]+1){
                d[p.X+a[i].X-i][p.Y+a[i].Y] = d[p.X][p.Y]+1;
                q.push({p.X+a[i].X-i,p.Y+a[i].Y});
            }
        }
    }
}
bool dfs(pll p){
    vis[p.X][p.Y] = 1;
    int n1 = min(n,p.X),m1 = min(m,p.Y);
    rep(i,1,n1+1){
        if (p.X+a[i].X+a[i].Y+p.Y-i > r) continue;
        if (vis[p.X+a[i].X-i][p.Y+a[i].Y] == 1){
            //debug(p.X);
          //  debug(p.Y);
            return 1;
        }
        if (vis[p.X+a[i].X-i][p.Y+a[i].Y] == 2) continue;
        if (dfs({p.X+a[i].X-i,p.Y+a[i].Y})) return 1;
    }
    rep(i,1,m1+1){
        if (p.X+b[i].X+b[i].Y+p.Y-i > r) continue;
        if (vis[p.X+b[i].X][p.Y+b[i].Y-i] == 1){
      //      debug(p.X+b[i].X);
        //    debug(p.Y+b[i].Y-i);
            return 1;
        }
        if (vis[p.X+b[i].X][p.Y+b[i].Y-i] == 2) continue;
        if (dfs({p.X+b[i].X,p.Y+b[i].Y-i})) return 1;
    }
    vis[p.X][p.Y] = 2;
    return 0;
}
void dfs2(ll x,ll y){
    ll n1 = min(n,x),m1 = min(m,y),mx = -1;
    if (x+y > r){
        dp[x][y] = 0;
        return;
    }
    rep(i,1,n1+1){
        if (x+y+a[i].X+a[i].Y-i > r) continue;
        if (x+a[i].X-i == 300 && a[i].Y+y == 200)  debug(dp[x+a[i].X-i][a[i].Y+y]);
        if (dp[x+a[i].X-i][a[i].Y+y] == -1) dfs2(x+a[i].X-i,y+a[i].Y);
        if (x+a[i].X-i == 300 && a[i].Y+y == 200)  debug(dp[x+a[i].X-i][a[i].Y+y]);
        if (x == 1 && y == 99 && dp[x+a[i].X-i][y+a[i].Y] > mx){
         //   debug(x+a[i].X-i);
           // debug(y+a[i].Y);
           // debug(dp[x+a[i].X-i][y+a[i].Y]);
            //debug(i);
        }
        mx = max(mx,dp[x+a[i].X-i][y+a[i].Y]);
    }
    rep(i,1,m1+1){
        if (x+y+b[i].X+b[i].Y-i > r) continue;
        if (x + b[i].X == 300 && y+b[i].Y-i == 200) debug(dp[x+b[i].X][y+b[i].Y-i]);
        if (dp[x+b[i].X][b[i].Y+y-i] == -1) dfs2(x+b[i].X,y+b[i].Y-i);
        if (x == 1 && y == 99 && dp[x+b[i].X][y+b[i].Y-i] > mx){
            //debug(x+b[i].X);
            //debug(y+b[i].Y-i);
           // debug(mx);
        }
        mx = max(mx,dp[x+b[i].X][y+b[i].Y-i]);
       // if (x == h && y == t) debug(mx);
    }
 //   if (x == h && y == t) debug(mx);
    dp[x][y] = mx+1;
    if (x == 300 && y == 200) debug(mx+1);
}
int main(){
    //ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(d,63,sizeof d);
    rep(i,0,N) rep(j,0,N) dp[i][j] = -1;
    cin >> h >> t >> r;
    cin >> n;
    rep(i,1,n+1) cin >> a[i].X >> a[i].Y;
    cin >> m;
    rep(i,1,m+1) cin >> b[i].X >> b[i].Y;
    bfs();
    if (d[0][0] < inf){
        cout << "Ivan" << endl << d[0][0];
        return 0;
    }
    if(dfs({h,t})){
        cout << "Draw";
        return 0;
    }
  //  debug(2);
    cout << "Zmey" << endl;
    dfs2(h,t);
    cout << dp[h][t]+1 << endl;
    debug(dp[300][200]);
    return 0;
}