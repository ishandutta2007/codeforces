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
typedef pair <ll,pair<ll,ll> >  pll;
const ll N = 1e6+30,inf = 1e10,mod=1e9+7;
ll a[N];
pll dp[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    rep (i,0,n) cin >> a[i];
    if (n == 1){
        cout << 0;
        return 0;
    }
    dp[0].X = 0;
    dp[0].Y.X = a[0];
    dp[0].Y.Y = a[0];
    dp[1].X = abs(a[0]-a[1]);
    dp[1].Y = {min(a[0],a[1]),max(a[0],a[1])};
    rep(i,2,n){
        if (abs(a[i]-a[i-1])+dp[i-2].X > dp[i-1].X+max(dp[i-1].Y.X-a[i],a[i]-a[i])+max(a[i]-dp[i-1].Y.Y,a[i]-a[i])){
            dp[i].X = abs(a[i]-a[i-1])+dp[i-2].X;
            dp[i].Y.X = min(a[i],a[i-1]);
            dp[i].Y.Y = max(a[i],a[i-1]);
            //debug(i);
        }
        else{
            dp[i].X = dp[i-1].X+max(dp[i-1].Y.X-a[i],a[i]-a[i])+max(a[i]-dp[i-1].Y.Y,a[i]-a[i]);
            dp[i].Y.X = min(dp[i-1].Y.X,a[i]);
            dp[i].Y.Y = max(dp[i-1].Y.Y,a[i]);
        }
    }
    debug(dp[n-2].Y.X);
    cout << dp[n-1].X;
}