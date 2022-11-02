#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
vector<int> adj[N],adj2[N];
int c[N];
int n,m;
inline int nxt(int a, int k){
    if (a < k) return a+1;
    return 1;
}
inline int bef(int a,int k){
    if (a > 1) return a-1;
    return k;
}
bool dfs(int v,int col,int k){
    c[v] = col;
    for (int u : adj[v]){
        if (!c[u]){
            if (!dfs(u,nxt(col,k),k)) return 0;
        }
        else if (c[u] != nxt(c[v],k)) return 0;
    }
    for (int u : adj2[v]){
        if (!c[u]){
            if (!dfs(u,bef(c[v],k),k)) return 0;
        }
        else if (c[u] != bef(c[v],k)) return 0;
    }
    return 1;
}
bool check(int k){
    memset(c,0,sizeof c);
    rep(i,1,n+1) if (!c[i]) if (!dfs(i,1,k)) return 0;
    return 1;
}
int binary(){
    int l = 1;
    int r = n+1;
    int mid;
    while (r-l > 1){
        mid = (l+r)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    return l;
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    bool f = 0;
    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj2[v].pb(u);
        if (u == v) f = 1;
    }
    if (f){
        cout << 1 << endl;
        return 0;
    }
    ll ans = binary();
    while (2*ans <= n && check(2*ans)) ans*=2;
    while (3*ans <= n && check(3*ans)) ans*=3;
    while (5*ans <= n && check(5*ans)) ans*=5;
    while (7*ans <= n && check(7*ans)) ans *= 7;
    while (11*ans <= n  && check(11*ans)) ans *= 11;
    while (17*ans <= n && check(17*ans)) ans*=17;
    while (19*ans <= n && check(19*ans)) ans*=19;
    while (41*ans <= n && check(41*ans)) ans *= 41;
    while (107*ans <= n && check(107*ans)) ans*=107;
    while (271*ans <= n && check(271*ans)) ans*=271;
    while (307*ans <= n && check(307*ans)) ans*=307;
    while (907*ans <= n && check(907*ans)) ans *= 907;
    while(53 * ans <= n && check(53*ans)) ans*=53;
    while (3673*ans <= n && check(3673*ans)) ans *= 3673;
    while(10007*ans <= n && check(10007*ans)) ans *= 10007;
    while (16097*ans <= n && check(16097*ans)) ans *= 16097;
    while (23*ans <= n && check(23*ans)) ans *= 23;

    cout << ans << endl;
    return 0;
}