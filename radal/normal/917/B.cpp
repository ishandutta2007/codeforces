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
constexpr int N = 1e2+20,mod = 1e9+7,inf = 1e9+10;
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
int din[N];
char dp[N][N][30];
vector<pair<int,char> > adj[N];
void f(int v,int u,int j){
    if (dp[v][u][j] != 'C') return;
    if (j == 27){
        dp[v][u][j] = 'B';
        return;
    }
    f(v,u,j+1);
    if (dp[v][u][j+1] == 'A'){
        dp[v][u][j] = 'A';
        return;
    }
    dp[v][u][j] = 'B';
    for (auto w : adj[v]){
        int d = w.Y-'a';
        if (d < j) continue;
        f(u,w.X,d);
        if (dp[u][w.X][d] == 'B'){
            dp[v][u][j] = 'A';
            return;
        }
    }
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m;
    rep(i,0,m){
        int u,v;
        char c;
        cin >> u >> v >> c;
        adj[u].pb({v,c});
        din[v]++;
    }
    vector<int> to,ve;
    rep(i,1,n+1){
        rep(j,1,n+1){
            rep(k,0,28){
                dp[i][j][k] = 'C';    
            }
        }
        if (!din[i]) ve.pb(i);
    }
    while (!ve.empty()){
        int v = ve.back();
        ve.pop_back();
        to.pb(v);
        for (auto u : adj[v]){
            din[u.X]--;
            if (!din[u.X]) ve.pb(u.X);
        }
    }
    rep(i,1,n+1) rep(j,1,n+1) f(i,j,0);
    rep(i,1,n+1){
        rep(j,1,n+1){
            cout << dp[i][j][0];
        }
        cout << endl;
    }
}