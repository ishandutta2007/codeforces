#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
const long long int N=3e5+10,mod = 1e9+7,inf=1e18,dlt = 12251;
ll poww(int a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k%2))%mod;
}
vector<pll> adj[N];
vector<int> ve;
bool vis[N];
void dfs(int v){
    for (pll u : adj[v]){
        if (vis[u.Y]) continue;
        vis[u.Y] = 1;
        dfs(u.X);
    }
    ve.pb(v);
}
int main(){
    int n,k;
    cin >> n >> k;
    rep(i,0,k) rep(j,0,k) adj[i].pb({j,i*k+j});
    dfs(0);
    int i = 0,sz = ve.size();
    while (n--){
        cout << char('a'+ve[i]);
        i++;
        if (i == sz) i = 1;
    }

    return 0;
}