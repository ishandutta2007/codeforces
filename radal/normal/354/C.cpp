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
const long long int N=3e5+10,mod = 2e18,inf=1e18;
const long double eps = 0.0001;
ll poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    r *= r;
    r %= mod;
    return ((k%2) ? (r*a)%mod : r);
}
int n,k;
int a[N];
int binary(ll val){
    if (a[0] > val) return -1;
    if (val >= a[n-1]) return n-1;
    int m,l = 0,r = n;
    while (r-l > 1){
        m = (l+r)/2;
        if (a[m] > val) r = m;
        else l = m;
    }
    return l;
}
int count(int l,int r){
    int u,v;
    v = binary(r);
    u = binary(l-1);
    return v-u;
}
int main(){
    ios :: sync_with_stdio(0);
    cin >> n >> k;
    int mi = 1e9;
    rep(i,0,n){
        cin >> a[i];
        mi = min(mi,a[i]);
    }
    sort(a,a+n);
    int maxv=a[n-1];
    repr(i,mi,1){
        if (k >= i){
            cout << i;
            return 0;
        }
        bool f = 1;
        for(int j = 1; j*i <= maxv; j++){
            if (count(j*i+k+1,(j+1)*i-1)){
                f=0;
                break;
            }
        }
        if (f){
            cout << i;
            return 0;
        }
    }
}