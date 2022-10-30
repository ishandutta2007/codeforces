#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Os")
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
const long long int N=5e5+30,inf = 1e18;
pair<ll,ll> a[N];
vector <pair<ll,ll> > ord;
ll dp[N],ind[N];

int main(){
    ll n;
    cin >> n;
    rep (i,0,n){
        cin >> a[i].X >> a[i].Y;
        ind[i] = -1;
    }
    sort(a,a+n);
    ord.pb(a[0]);
 //   cout << a[0].X << ' ' << a[0].Y << endl;
    rep(i,1,n){
        if (a[i].X != a[i-1].X){
            ord.pb(a[i]);
   //         cout << a[i].X << ' ' << a[i].Y << endl;
        }
    }
    n=ord.size();
    ll en[n+10];
    dp[0] = 1;
    ll sz=1;
    en[0] = ord[0].Y;
    rep(i,1,n){
        ll ind=0;
        if (en[0] >= ord[i].X){
            dp[i] = 1;
            if (en[0] > ord[i].Y){
                en[0] = ord[i].Y;
            }
            continue;
        }
        if (en[sz-1] < ord[i].X){
            dp[i] = sz+1;
            en[sz] = ord[i].Y;
            sz++;
        }
        ind = lower_bound(en,en+sz,ord[i].X-1)-en;
        dp[i] = ind+1;
        if (en[ind] > ord[i].Y){
            en[ind] = ord[i].Y;
        }
    }
    cout << sz;
    return 0;
}