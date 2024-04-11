#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const int N=3e5+10;
ll begn[N][3];
ll a[N];
vector<pair<ll,ll> >z;
ll dp[N],mx[N];
ll binary(ll l, ll r, ll val){
    ll m;
    while (r-l > 1){
        m = (l+r)/2;
        if (z[m].X <= val){
            l = m;
            continue;
        }
        else{
            r = m;
        }
    }
    //debug(a[r]);
   
    return l;
}
int main(){
    string s;
    cin >> s;
    ll n =s.size();
    rep (i,0,n){
        a[i] = int(s[i])-int('0');
    }
    begn[0][a[0]%3] = 0;
    begn[0][(a[0]+1)%3] = -1;
    begn[0][(a[0]+2)%3] = -1;
    rep (i,1,n){
        if (a[i]%3 == 0){
            begn[i][0] = i;
            begn[i][1] = begn[i-1][1];
            begn[i][2] = begn[i-1][2];
        }
        if (a[i]%3 == 1){
            begn[i][0] = begn[i-1][2];
            begn[i][1] = i;
            begn[i][2] = begn[i-1][1];
        }
        if (a[i]%3 == 2){
            begn[i][0] = begn[i-1][1];
            begn[i][1] = begn[i-1][2];
            begn[i][2] = i;
        }
    }
    rep (i,0,n){
        if (begn[i][0] != -1){
            z.pb(mp(i,begn[i][0]));
        }
    }
    ll sz = z.size();
  //  debug(sz);
    rep(i,0,sz){
        if (z[i].Y <= z[0].X){
            dp[i] = 1;
        }
        else{
            dp[i] = 1+mx[binary(0,i,z[i].Y-1)];
        }
        if (!i) mx[0] = 1;
        else mx[i] = max(mx[i-1],dp[i]);
       // debug(i);
     //   debug(z[i].X);debug(z[i].Y);
    }
    cout << mx[sz-1];
   // ll ans = 0;
  //  rep (i,0,sz){
    //    ans = max(ans,dp[i]);
  //  }
   // cout << ans << endl;
}