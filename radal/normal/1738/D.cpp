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

vector<int> out[N],vec;
int b[N];
bool vis[N];
void dfs(int v){
    vec.pb(v);
    vis[v] = 1;
    int tmp = -1;
    for (int u : out[v]){
        if (out[u].empty())
            dfs(u);
        else 
            tmp = u;
    }
    if (tmp != -1) dfs(tmp);
}
inline void solve(){
    int n,k;
    cin >> n;
    k = n;
    rep(i,1,n+1){
        out[i].clear();
        vis[i] = 0;
    }
    vec.clear();
    rep(i,1,n+1){
        cin >> b[i];
        if (k == n && b[i] < i) k = i-1;
        if (b[i] > 0 && b[i] < n+1) out[b[i]].pb(i);
    }
    rep(i,1,n+1) if (b[i] == 0 || b[i] == n+1){
        if (out[i].empty()){
            vis[i] = 1;
            vec.pb(i);
        }
    }
    rep(i,1,n+1) if ((b[i] == 0 || b[i] == n+1) && !vis[i]){
        dfs(i);
    }
    cout << k << endl;
    for (int u : vec) cout << u << ' ';
    cout << endl;
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