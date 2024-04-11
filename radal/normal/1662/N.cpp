#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define all(x) x.begin(),x.end() 
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;

constexpr int N = 2e3+20,mod = 1e9+7,inf = 1e9+10,maxm = (1 << 18)+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
 //   if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(ll a,ll k,ll m){
    if (k < 0) return 0;
    ll z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%m;
        a = 1ll*a*a%m;
        k /= 2;
    }
    return z;
}
int a[N][N],r[N],c[N],n;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    vector<pair<int,pll> > ve;
    rep(i,0,n){
        rep(j,0,n){
            cin >> a[i][j];
            ve.pb({a[i][j],{i,j}});
        }
    }
    ll ans = 1ll*n*n*(n-1)*(n-1)/2;
    sort(all(ve));
    for (auto p : ve){
        ans -= 1ll*r[p.Y.X]*c[p.Y.Y];
        r[p.Y.X]++;
        c[p.Y.Y]++;
    }
    cout << ans;
}