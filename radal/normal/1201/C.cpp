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
const long long int N=1e6+30,mod = 1e9+7;
vector <ll> sum;
ll binary(ll l , ll r , ll val){
    ll m = (l+r)/2;
    while (r-l > 1){
        m = (l+r)/2;
        if (sum[m] < val){
            l = m;
        }
        else{
            r = m;
        }
    }
    return l;
}
ll a[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    ll n,k;
    cin >> n>>k;
    rep(i,0,n){
        cin >> a[i];
    }
    if (n == 1){
        cout << a[0] + k << endl;
        return 0;
    }
    sort(a,a+n);
    ll p = a[n/2+1]-a[n/2];
    sum.pb(p);
    rep(i,n/2+2,n){
        p += (i-n/2)*(a[i]-a[i-1]);
        sum.pb(p);
    }
    if (k <= sum[0]){
        cout << a[n/2]+k << endl;
        return 0;
    }
   // debug(sum.size());
    ll ind = binary(0,n/2,k);
    debug(ind);
    cout << a[ind+n/2+1]+(k-sum[ind])/(ind+2);
}