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
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=1e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,a,b;
        cin >> n >> a >> b;
        if (b == 1){
            cout << "YES" << endl;
            continue;
        }
        if (a == 1){
            cout << ((n%b == 1) ? "YES" : "NO" ) << endl;
            continue;
        }
        ll z = 1;
        bool f=0;
        while (z <= n){
            if ((n-z)%b == 0){
                f=1;
                break;
            }
            z*= a;
        }
        cout << ((f) ? "YES" : "NO" ) << endl;
    }
    return 0;
}