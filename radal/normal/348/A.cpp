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
const long long int N=3e5+30,mod = 1e9+7,inf=1e9;
ll n,sum=0;
ll a[N];
bool check(ll x){
    return sum <= x*(n-1);
}
ll binary(ll l,ll r){
    ll mid;
    if (check(l)) return l;
    while (r-l > 1){
        mid = (l+r)/2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return r;
}
int main(){
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        sum += a[i];
    }
    sort(a,a+n);
    cout << binary(a[n-1],2e10);
    return 0;
}