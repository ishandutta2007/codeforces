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
ll left_most(ll val){
    ll z = 1;
    ll t = 1;
    while (z <= val){
        z*=2;
        t++;
    }
    return t-1;
}
ll a[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll T;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        rep (i,0,n){
            ll x;
            cin >> x;
            a[i] = left_most(x);
          //  cout << a[i] << ' ';
        }
    //    cout << endl;
        sort(a,a+n);
        ll ans=0;
        rep(i,0,n){
      //      cout << a[i] << ' ';
            ll cnt = 1;
            while (i < n-1 && a[i+1] == a[i]){
                i++;
                cnt++;
            }
            ans+=cnt*(cnt-1)/2;
        }
       // cout << endl;
        cout << ans << endl;
    }
    return 0;
}