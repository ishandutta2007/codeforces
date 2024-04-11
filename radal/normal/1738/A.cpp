#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 2e5+15,mod = 998244353,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
   // if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}

int a[N],b[N];
inline void solve(){
    int n;
    cin >> n;
    rep(i,0,n)
        cin >> a[i];
    vector<int> v1,v2;
    rep(i,0,n){
        cin >> b[i];
        if (a[i]) v2.pb(b[i]);
        else v1.pb(b[i]);
    }
    sort(all(v1));
    sort(all(v2));
    if (v1.size() > v2.size()) swap(v1,v2);
    ll ans = 0;
    if (v1.size() == v2.size()){
        for (int u : v1) ans += u;
        for (int u : v2) ans += u;
        ans *= 2;
        ans -= min(v1[0],v2[0]);
        cout << ans << endl;
        return;
    }
    int t = v2.size()-v1.size();
    int sz2 = v2.size();
    rep(i,0,t) ans += v2[i];
    rep(i,t,sz2) ans += 2*v2[i];
    for (int u : v1) ans += 2*u;
    cout << ans << endl;

}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}