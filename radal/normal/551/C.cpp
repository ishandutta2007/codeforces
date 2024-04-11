#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+30,mod = 1e9+7,inf=1e9;
int n,m,k;
ll a[N],b[N];
bool check(ll t){
    int p=n;
    bool f = 0;
    rep(i,0,n){
        b[i] = a[i];
        if (a[i] != 0 && !f){
            p = i;
            f = 1;
        }
    }
    rep(i,0,m){
        if (p == n) return 1;
        ll T = t-p-1;
        while(T > 0 && p < n){
            ll mi = min(b[p],T);
            b[p]-=mi;
            T-=mi;
            if (!b[p])p++;
            T--;
        }
      //  debug(p);
        while (p < n && !b[p])p++;
    }
    rep(i,0,n) if (b[i]) return 0;
    return 1;
}
ll binary(ll l,ll r){
    ll mid;
    if (check(l)) return l;
    while (r-l > 1){
        mid = (r+l)/2;
        if (check(mid)) r = mid;
        else l=mid;
    }
    return r;
}
int main(){
    cin >> n >> m;
    rep(i,0,n){
        cin >> a[i];
    }
    cout << binary(0,1e18);
    return 0;
}