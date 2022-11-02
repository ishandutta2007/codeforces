#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
//#pragma GCC optimize("unroll-loops,O2")
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
constexpr int N = 2e5+10,mod = 998244353,inf = 1e9+10;
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
int a[N],b[N],vis[N];
inline void solve(){
    int n,s,mx = 0;
    cin >> n >> s;
    rep(i,0,n){
        cin >> a[i];
        vis[i+1] = 0;
    }
    vector<int> v1,v2;
    rep(i,0,n){
        cin >> b[i];
        if (b[i] != -1){
            mx = max(mx,a[i]-b[i]);
            vis[b[i]] = 1;
        }
        else v1.pb(a[i]);
    }
    if (mx > s){
        cout << 0 << endl;
        return;
    }
    rep(i,1,n+1) if (!vis[i]) v2.pb(i);
    sort(all(v1));
    reverse(all(v1));
    reverse(all(v2));
    int ans = 1,po = 0,sz = v1.size();
    rep(i,0,sz){
        while (po < sz && v1[i]-v2[po] <= s) po++;
        ans = 1ll*ans*(po-i)%mod;
    }
    cout << ans << endl;
}
int main(){
   ios :: sync_with_stdio(0); cin.tie(0);
   int T = 1;
   cin >> T;
   while (T--){
       solve();
   }
   return 0;
}