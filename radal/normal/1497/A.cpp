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
const long long int N=1e2+10,mod = 2e18,inf=1e18;
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
    ios :: sync_with_stdio(0);
    int T;
    cin >> T;
    while (T--){
        memset(b,0,sizeof b);
        int n;
        cin >> n;
        rep(i,0,n) cin >> a[i];
        sort(a,a+n);
        rep(i,0,n){
            if (!b[a[i]])cout << a[i] << ' ';
            b[a[i]]++;
        }
        rep(i,0,N){
            rep(j,0,b[i]-1){
                cout << i << ' ';
            }
        }
        cout<< endl;
    }
}