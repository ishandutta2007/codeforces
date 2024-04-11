#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O3")
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
constexpr int N = 2e5+10,mod = 1e9+7,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
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
void solve(){
    int n;
    string s,t;
    cin >> n >> s >> t;
    vector<int> v1,v2;
    if (s[0] != t[0]){
        cout << -1 << endl;
        return;
    }
    int po = 0;
    while (po < n){
        while (po+1 < n && s[po+1] == s[po]) po++;
        v1.pb(po);
        po++;
    }
    po = 0;
    while (po < n){
        while (po+1 < n && t[po+1] == t[po]) po++;
        v2.pb(po);
        po++;
    }
    if (v1.size() != v2.size()){
        cout << -1 << endl;
        return;
    }
    ll ans = 0;
    int sz = v1.size();
    rep(i,0,sz) ans += abs(v1[i]-v2[i]);
    cout << ans << endl;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}