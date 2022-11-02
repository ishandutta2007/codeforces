#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,sse4,avx2")
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
constexpr int N = 1e5+20,mod = 998244353 ,inf = 1e9+10;

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
pll a[N],b[N];
vector<int> out[N],in[N];
bool vis[N][2];
void dfs(int v){
    vis[v][0] = 1;
    for (int u : out[v]){
        if (!vis[u][0]) dfs(u);
    }
}
void sfd(int v){
    vis[v][1] = 1;
    for (int u : in[v]){
        if (!vis[u][1]) sfd(u);
    }
}
void solve(){
    int n;
    cin >> n;
    rep(i,0,n){
        vis[i][0] = 0;
        vis[i][1] = 0;
        cin >> a[i].X;
        a[i].Y = i;
        out[i].clear();
        in[i].clear();
    }
    rep(i,0,n){
        cin >> b[i].X;
        b[i].Y = i;
    }
    sort(a,a+n);
    sort(b,b+n);
    rep(i,1,n){
        out[a[i].Y].pb(a[i-1].Y);
        in[a[i-1].Y].pb(a[i].Y);
        out[b[i].Y].pb(b[i-1].Y);
        in[b[i-1].Y].pb(b[i].Y);
    }
    dfs(a[n-1].Y);
    sfd(a[n-1].Y);
    rep(i,0,n){
        cout << (vis[i][0]&vis[i][1]);
    }
    cout << endl;
}
int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
    int T = 1;
    cin >> T;
    while(T--){
        solve();
    }
}