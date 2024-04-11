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
const int N=2e5+10;
ll sum[N],cnt[N],a[N];
ll binary(ll l, ll r, ll val){
    ll m;
    while (r-l > 1){
        m = (l+r)/2;
        if (sum[m] <= val){
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
    ll T;
    cin >> T;
    while (T--){
        ll n,p,k;
        cin >> n >> p >> k;
        rep (i,1,n+1){
            cin >> a[i];
        }
        sort(a+1,a+1+n);
        sum[0] = 0;
        rep(i,1,k){
            sum[i] = sum[i-1]+a[i];
        }
        rep(i,k,n+1){
            sum[i] = sum[i-k]+a[i];
        }
        ll p1=n;
        while (sum[p1] > p){
            p1--;
        }
        cout << p1 << endl;
    }
}