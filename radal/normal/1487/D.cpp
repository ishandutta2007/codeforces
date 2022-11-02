#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=4e18,maxk = 1e5+20;
const long double eps = 0.0001;
ll n;
ll binary(ll l , ll r){
    ll m;
    while (r-l > 1){
        m = (l+r)/2;
        ll a = 2*m+1;
        if ((a*a-1)/2+1 <= n) l = m;
        else r = m;
    }
    return l;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        ll s;
        cin >> n;
        s = sqrt(n)+1;
        ll c,b,cnt = 0;
        /*rep(a,2,3*s){
            if (a > n) break;
            if (a%2 == 0) continue;
            b = (a+1)*(a-1)/2;
            if (b > n) break;
            c = b+1;
            if (c > n) break;
            if (a*a+b*b == c*c && b+c == a*a){
                cnt++;
            }
        }*/
        cout << binary(0,n+1) << endl; 
    }
    return 0;
}