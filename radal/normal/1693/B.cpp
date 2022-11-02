#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr int N = 3e5+20,mod = 998244353,inf = 1e9+10;
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
int p[N],l[N],r[N];
ll mx[N];
ll sm[N];
vector<int> adj[N];
inline void solve(){
    int n;
    cin >> n;
    rep(i,1,n+1) adj[i].clear();
    rep(i,2,n+1){
        cin >> p[i];
        adj[p[i]].pb(i);
    }
    rep(i,1,n+1) cin >> l[i] >> r[i];
    int ans = 0;
    repr(i,n,1){
        sm[i] = 0;
        for (int u : adj[i]) sm[i] += mx[u];
        if (sm[i] < l[i]){
            ans++;
            mx[i] = r[i];
            continue;
        }
        else{
            if (sm[i] < r[i]) mx[i] = sm[i];
            else mx[i] = r[i];
        }
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