#include <bits/stdc++.h>
#pragma GCC target("sse,sse2")
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
constexpr int N = 3e5+10,mod = 998244353,inf = 1e9+10;
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
        k /= 2;
    } 
    return z; 
}
vector<int> ind[N];
int a[N],k,calc,sz[N];
bool cnt(int l,int r,int x){
    int L = lower_bound(all(ind[x]),l)-ind[x].begin();
    if (sz[x] <= L+calc || ind[x][L+calc] >= r) return 0;
    return 1;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n,q;
    cin >> n >> q;
    rep(i,0,n){
        cin >> a[i];
        sz[a[i]]++;
        ind[a[i]].pb(i);
    }
    while (q--){
        int l,r;
        cin >> l >> r >> k;
        l--;
        calc = (r-l)/k;
        int tt = 80;
        int ans = inf;
        rep(i,0,tt){
            int val = a[l+rng()%(r-l)];
            if (cnt(l,r,val)){
                ans = min(ans,val);
            }
        }
        if (ans == inf) cout << -1 << endl;
        else cout << ans << endl;
    }
    return 0;
}