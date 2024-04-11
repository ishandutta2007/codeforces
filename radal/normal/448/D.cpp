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
ll n,m,k;
bool check(ll x){
    ll sum = 0;
    rep(i,1,n+1){
       sum += min(m,(x-1)/i);
    }
    return sum < k;
}
ll binary(ll l,ll r){
    ll mid;
    if (check(r)) return r;
    while (r-l > 1){
        mid = (l+r)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    return l;
}
int main(){
    cin >> n >> m >> k;
    cout << binary(0,n*m);
    return 0;
}