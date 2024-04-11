#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const long long int N=1e5+10,mod = 2e18,inf=1e18;
const long double eps = 0.0001;
ll poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    r *= r;
    r %= mod;
    return ((k%2) ? (r*a)%mod : r);
}
ll a[N];
int b[N];
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,k;
        cin >> n >> k;
        rep(i,0,k-3) cout << 1 << ' ';
        n -= (k-3);
        if (n%3 == 0){
            cout << n/3 << ' ' << n/3 << ' ' << n/3 << endl;
            continue;
        }
        if (n%2){
            cout << n/2 << ' ' << n/2 << ' ' << 1 << endl;
            continue;
        }
        if (n == 4){
            cout << 2 << ' ' << 1 << ' ' << 1 << endl;
            continue;
        }
        if ((n/2)%2){
            cout << n/2-1 << ' ' << n/2-1 << ' ' <<2 << endl;
            continue;
        }
        cout << n/2  << ' '<< n/4 << ' ' <<  n/4 << endl;
    }
}