#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef pair <ll,ll>  pll;
const ll N = 1e3+30,inf = 1e10,mod=1e9+7;
pll par[N][N],t[N];
pair<pll,ll> a[N];
ll dp[N][N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n,k;
    cin >> n;
    rep(i,0,n) {
        cin >> a[i].X.X >> a[i].X.Y;
        a[i].Y = i;
    }
    cin >> k;
    rep(i,0,k){
        cin >> t[i].X;
        t[i].Y = i;
    }
    rep(i,0,n){
        rep(j,0,k) par[i][j] = {-1,-1};
    }
    sort(t,t+k);
    sort(a,a+n);
    if (k == 1){
        ll mx = 0;
        ll j = -1;
        rep(i,0,n){
            if (a[i].X.X > t[0].X) break;
            if (mx < a[i].X.Y){
                mx= a[i].X.Y;
                j = a[i].Y;
            }
        }
        if (j == -1) cout << 0 <<  ' ' << 0;
        else cout << 1 << ' ' << mx << endl << j+1 << ' ' << 1;
        return 0;
    }
    rep(i,0,k){
        if (t[i].X >= a[0].X.X){
            dp[0][i] = a[0].X.Y;
        }
        else{
            dp[0][i] = 0;
        }
    }
    rep(i,0,n){
        if (t[0].X >= a[i].X.X){
            dp[i][0] = a[i].X.Y;
        }
        else{
            if (i) {
                dp[i][0] = dp[i-1][0];
                par[i][0] = {i-1,0};
            }
            else dp[i][0] = 0;
        }
    }
    rep(i,1,n){
        rep(j,1,k){
            ll x,y=0,z,mx;
            x = dp[i-1][j];
            if (a[i].X.X <= t[j].X) y = a[i].X.Y + dp[i-1][j-1];
            z = dp[i][j-1];
            mx = max(x,max(y,z));
            if (x == mx){
                par[i][j] = {i-1,j};
            }
            if (y == mx){
                par[i][j] = {i-1,j-1};
            }
            if (z == mx){
                par[i][j] = {i,j-1};
            }
            dp[i][j] = mx;
        }
    }
    vector<pll> out;
    int i=n-1,j=k-1;
    while (par[i][j].X != -1){
        if (dp[i][j] > dp[par[i][j].X][par[i][j].Y]){
            out.pb(mp(a[i].Y,t[j].Y));
        }
        pll p = par[i][j];
        i = p.X;
        j = p.Y;
    }
    if (a[i].X.X <= t[j].X) out.pb(mp(a[i].Y,t[j].Y));
    cout << out.size() << ' ' << dp[n-1][k-1] << endl;
  //  debug(a[i].Y);
    //debug(t[j].Y);
    for (pll p : out){
        cout << p.X +1 << ' ' << p.Y+1 << endl;
    }
}