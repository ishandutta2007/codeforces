#include <bits/stdc++.h>
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#pragma GCC optimize("unroll-loops")
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
const int N = 1e6+20,mod = 1e9+7 ,inf = 1e9+10;
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
vector<int> adj[N];
int sz[N],n,h[N],cnt[N];
bitset<N> bt;
ll ans;
void pre(int v,int p){
    sz[v] = 1;
    for (int u : adj[v]){
        if(u == p) continue;
        pre(u,v);
        sz[v] += sz[u];
    }
}
int cent(int v,int p){
    for (int u : adj[v]){
        if (u == p)continue;
        if (sz[u]*2 > n)
            return cent(u,v);
    }
    return v;
}
void dfs(int v,int p){
    ans += h[v];
    sz[v] = 1;
    for (int u : adj[v]){
        if (u != p){
            h[u] = h[v]+1;
            dfs(u,v);
            sz[v] += sz[u];
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i,2,n+1){
        int x;
        cin >> x;
        adj[x].pb(i);
        adj[i].pb(x);
    }
    pre(1,0);
    int ce = cent(1,0);
    h[ce] = 1;
    dfs(ce,0);
    for (int u : adj[ce]){
        cnt[sz[u]]++;
    }
    vector<int> ve;
    rep(i,1,n){
        int t = (cnt[i]-1)/2;
        cnt[i] -= 2*t;
        cnt[2*i] += t;
        if (cnt[i]){
            rep(j,0,cnt[i]) ve.pb(i);
        }
    }
    bt[0] = 1;
    for (int u : ve){
        bt |= (bt << u);
    }
    ll mx = 0;
    for (int i = bt._Find_first(); i < (int)bt.size(); i = bt._Find_next(i)){
        mx = max(mx,1ll*i*(n-1-i));
    }
    cout << ans+mx;
}