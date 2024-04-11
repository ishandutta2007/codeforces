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
const long long int N=3e5+20,mod = 1e9,inf=4e18,maxm = 2e5+20;
const long double eps = 0.0001;
pair<pll,pll> dp[N];
pair<ll,pll> e[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,m) cin >> e[i].Y.X >> e[i].Y.Y >> e[i].X;
    sort(e,e+m);
    rep(i,0,m){
        int u = e[i].Y.X,v = e[i].Y.Y,w = e[i].X;
        if (dp[u].Y.Y < w){
            if (dp[u].Y.X+1 > dp[v].Y.X){
                if (w != dp[v].Y.Y) dp[v].X = dp[v].Y;
                dp[v].Y.X = dp[u].Y.X+1;
                dp[v].Y.Y = w;
                continue;
            }
            if (w == dp[v].Y.Y) continue;
            if (dp[u].Y.X+1 > dp[v].X.X){
                dp[v].X.X = dp[u].Y.X+1;
                dp[v].X.Y = w;
                continue;
            }
            continue;
        }
        if (dp[u].X.X+1 > dp[v].Y.X){
            if (w != dp[v].Y.Y) dp[v].X = dp[v].Y;
            dp[v].Y.X = dp[u].X.X+1;
            dp[v].Y.Y = w;
            continue;
        }
        if (w == dp[v].Y.Y) continue;
        if (dp[u].X.X+1 > dp[v].X.X){
            dp[v].X.X = dp[u].X.X+1;
            dp[v].X.Y = w;
            continue;
        }
        continue;
    }
    ll mx = 0;
    rep(i,1,n+1) mx = max(mx,dp[i].Y.X);
    cout << mx;
}