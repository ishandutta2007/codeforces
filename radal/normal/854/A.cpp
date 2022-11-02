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
const long long int N=3e3+20,mod = 1e9+7,inf=1e6,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
ll modinv(ll n){
    return poww(n,mod-2)%mod;
}
int a[N];
int main(){
   // ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin >> n;
    if (n%2){
        cout << n/2 << ' ' <<  n/2+1 << endl;
    }
    else{
        int a = n/2-1,b = n/2+1;
        while (gcd(a,b) != 1){
            a--;
            b++;
        }
        cout << a << ' ' << b << endl;
    }
    return 0;
}