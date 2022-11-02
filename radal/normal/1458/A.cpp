#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e6+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
ll a[N],b[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    T = 1;
    while (T--){
       ll n,m,g=1;
       cin >> n >> m;
       rep(i,0,n){
           cin >> a[i];
           if (i > 1) g = gcd(g,abs(a[i]-a[i-1]));
           else if (i == 1) g = abs(a[i]-a[i-1]);
       }
       rep(i,0,m){
           cin >> b[i];
           if (n == 1){
               cout << b[i] + a[0] << ' ';
               continue;
           }
           cout << gcd(g,b[i]+a[0]) << ' ';
       }
    }
    return 0;
}