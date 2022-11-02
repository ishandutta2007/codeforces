#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 2e5+20,mod = 1e9+7 ,inf = 1e9+10,maxm = (1 << 10)+10;
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
int a[N];
inline void solve(){
    int n;
    cin >> n;
    ll ans = 0;
    rep(i,1,n+1){
        cin >> a[i];
        ans += a[i];
    }
    int q;
    cin >> q;
    map<pll,int> st;
    while (q--){
        int s,t,u;
        cin >> s >> t >> u;
        if (st.find({s,t}) != st.end()){
            int u = st[{s,t}];
            a[u]++;
            if (a[u] > 0) ans++;
            st.erase({s,t});
        }
        if (!u){
            cout << ans << endl;
            continue;
        }
        st[{s,t}] = u;
        if (a[u] > 0) ans--;
        a[u]--;
        cout << ans << endl;
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    //cin >> T;
    while (T--){
        solve();
    }
    return 0;
}