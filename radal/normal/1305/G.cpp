#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr ll N = 3e5+20,mod = 1e9+7,inf = 1e18+10,maxm = 1e6;
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
int dp[N][20][2];
int n,a[N],par[N],pr[N];
bool vis[N];
int getpar(int v){
    if (v == par[v]) return v;
    return par[v] = getpar(par[v]);
}
inline bool mg(int u,int v){
    if (v == -1) return 0;
    u = getpar(u);
    v = getpar(v);
    if (u == v) return 0;
    par[u] = v;
    return 1;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    n++;
    int mx = 0;
    rep(i,1,n){
        cin >> a[i];
        mx = max(mx,a[i]);
        par[i] = i;
    }
    int y = 1,lg = 0;
    while (y <= mx){
        y <<= 1;
        lg++;
    }
    sort(a,a+n);
    ll ans = 0;
    rep(g,0,19){
        memset(dp,-1,sizeof dp);
        rep(i,0,n){
            vis[i] = 0;
            if (dp[a[i]][lg][0] == -1){
                dp[a[i]][lg][0] = i;
                continue;
            }
            if (dp[a[i]][lg][1] == -1){
                if (getpar(i) != getpar(dp[a[i]][lg][0])){
                    dp[a[i]][lg][1] = i;
                    continue;
                }
                continue;
            }
        }
        repr(j,lg-1,0){
            rep(i,0,y){
                int x = (1 << j);
                rep(k,0,2) dp[i][j][k] = dp[i][j+1][k];
                if ((i&x) == 0 || dp[i-x][j+1][0] <= dp[i][j][1]) continue;
                if (dp[i][j][0] < dp[i-x][j+1][0]){
                    if (dp[i][j][0] == -1 || getpar(dp[i][j][0]) != getpar(dp[i-x][j+1][0])){
                        dp[i][j][1] = dp[i][j][0];
                    }
                    dp[i][j][0] = dp[i-x][j+1][0];
                    if (dp[i][j][1] < dp[i-x][j+1][1]) dp[i][j][1] = dp[i-x][j+1][1];
                    continue;
                }
                if (getpar(dp[i][j][0]) != getpar(dp[i-x][j+1][0])){
                    dp[i][j][1] = dp[i-x][j+1][0];
                    continue;
                }
                if (dp[i][j][1] < dp[i-x][j+1][1] && getpar(dp[i-x][j+1][1]) != getpar(dp[i][j][0])){
                    dp[i][j][1] = dp[i-x][j+1][1];
                }
            }
        }
        vector<pair<int,pll> > ve;
        ve.reserve(n);
        repr(i,n-1,0){
            pr[i] = getpar(i);
            int j = dp[y-a[i]-1][0][0];
            if (j == -1) continue;
            if (getpar(j) != getpar(i)){
                ve.pb({-a[i]-a[j],{i,j}});
                continue;
            }
            j = dp[y-a[i]-1][0][1];
            if (j == -1) continue;
            if (getpar(j) != getpar(i)){
                ve.pb({-a[i]-a[j],{i,j}});
            }
        }
        sort(ve.begin(),ve.end());
        for (auto u : ve){
            if (vis[pr[u.Y.X]]) continue;
            vis[pr[u.Y.X]] = 1;
            if (mg(u.Y.X,u.Y.Y)){
                ans -= u.X;
            }
        }
    }
    repr(i,n-1,0){
        ans -= a[i];
    }
    cout << ans;
}