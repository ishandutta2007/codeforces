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
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
vector<int> adj[N];
int cnt[N],sz;
bool vis[N];
int dp[N][400];
void dfs(int v){
    vis[v] = 1;
    sz++;
    for(int u : adj[v]) if(!vis[u]) dfs(u);
}
inline bool lucky(int v){
    while (v){
        if (v%10 != 4 && v%10 != 7){
            return 0;
        }
        v /= 10;
    }
    return 1;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp,63,sizeof dp);
    int n,m;
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    rep(i,1,n+1){
        if (vis[i]) continue;
        dfs(i);
        cnt[sz]++;
        sz=0;
    }
    vector<pll> ob;
    rep(i,1,N){
        if (cnt[i]){
            int z = 0;
            rep(j,0,20) if (cnt[i] > (1 << j)) z =  j;
            ob.pb({i,1});
            rep(j,0,z){
                int y = (1 << j);
                ob.pb({i*y,y});
            }
            cnt[i] -= (1 << z);
            repr(j,19,0){
                int y = (1 << j);
                if (cnt[i] >= y){
                    ob.pb({y*i,y});
                    cnt[i] -= y;
                }
            }
        }
    }
    sz = ob.size();
    dp[ob[0].X][0] = ob[0].Y;
    dp[0][0] = 0;
    int ans = n+2;
    rep(j,1,sz){
        rep(i,0,n+1){
            if (i < ob[j].X){
                dp[i][j] = dp[i][j-1];
                continue;
            }
            dp[i][j] = min(dp[i][j-1],ob[j].Y+dp[i-ob[j].X][j-1]);
        }
    }
    rep(i,4,n+1){
        if (lucky(i)){
            ans = min(ans,dp[i][sz-1]);
        }
    }
    if (ans == n+2) cout << -1;
    else cout << ans-1;
}