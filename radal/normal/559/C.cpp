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
typedef pair<int,int> pll;
const long long int N=2e5+10,mod = 1e9+7,inf=1e18;
int poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
int h,w,n;
vector<pll> ve;
ll fac[N];
map<pll,int> mp;
inline int mas(int x,int y,int z,int w){
    ll r = fac[z-x+w-y];
    ll t = poww((fac[z-x]*fac[w-y])%mod,mod-2);
    return (t*r)%mod;
}
ll f(int x,int y){
    if (mp.find({x,y}) != mp.end()) return mp[{x,y}];
    ll ans = mas(x,y,h,w);
    ans %= mod;
    rep(i,0,n){
        if (ve[i].X >= x && ve[i].Y >= y && (ve[i].X != x || ve[i].Y != y)){
            ll r = f(ve[i].X,ve[i].Y)*mas(x,y,ve[i].X,ve[i].Y)%mod;
            ans = ans+mod-r;
            ans %= mod;
        }
    }
    mp[{x,y}] = ans;
    return ans;
}
int main(){
    ios :: sync_with_stdio(0);
    fac[0] = 1;
    rep(i,1,N){
        fac[i] = fac[i-1]*i;
        fac[i] %= mod;
    }
    cin >> h >> w >> n;
    rep(i,0,n){
        int x,y;
        cin >> x >> y;
        ve.pb({x,y});
    }
    cout << f(1,1);
}