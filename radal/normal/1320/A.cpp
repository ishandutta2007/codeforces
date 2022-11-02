#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
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
const long long int N=1e6+30,mod = 1e9+7,inf=1e18;
ll b[N],dp[N];
pair <ll,ll> p[N];
ll binary(ll l, ll r, pair<ll,ll> val){
    while (r-l > 1){
        ll m = (r+l)/2;
        if (p[m].X > val.X || (p[m].X == val.X && p[m].Y > val.Y)){
            r = m;
        }
        else l = m;
    }
    return l;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    rep(i,0,n){
        cin >> b[i];
        b[i] -= (i+1);
        p[i] = mp(b[i],i);
    }
    sort(p,p+n);
  //  rep(i,0,n){
     //   cout << p[i].X << ' ';
 //   }
   // cout << endl;
    dp[0]=b[0]+1;
    ll ans=dp[0];
    rep (i,1,n){
        ll ind=binary(0,n,mp(b[i],i));
        if (ind == 0 || p[ind-1].X != p[ind].X){
            dp[i] = b[i]+i+1;
        }
        else{
            dp[i] = b[i]+i+1+dp[p[ind-1].Y];
        }
        ans=max(ans,dp[i]);
       // debug(i);debug(dp[i]);debug(ind);
    }
    cout << ans << endl;
    return 0;

}