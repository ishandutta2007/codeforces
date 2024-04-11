#include <bits/stdc++.h>
#pragma GCC optimize("O3,no-stack-protector,unroll-loops")
#pragma GCC target("avx2,fma")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tre
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
typedef pair<long double,long double> pld;
const long long int N = 3e5+10,mod = 1e9+7,inf = 1e9,sq = 500,maxm = 5e3+10,mod2 = 98765431;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
    if (a+b < 0) return a+b+mod;
    return a+b;
}
inline int poww(int n,int k){
    int c = 1;
    while (k){
        if (k&1) c = (1ll*c*n)%mod;
        n = (1ll*n*n)%mod;
        k >>= 1;
    }
    return c;
}
vector<int> adj[N];
string s;
int hsh[N],c[N],ans[N],hsh2[N];
set<pll> st[N];
void dfs(int v,int p){
    hsh[v] = mkay(1ll*hsh[p]*47%mod,(s[v]-'a'+1));
    hsh2[v] = mkay(1ll*hsh2[p]*47%mod2,(s[v]-'a'+1));
    st[v].insert({hsh2[v],hsh[v]});
    for (int u : adj[v]){
        if (u == p) continue;
        dfs(u,v);
        if (st[v].size() < st[u].size()) swap(st[u],st[v]);
        for (pll x : st[u]){
            st[v].insert(x);
        }
    }
    ans[v] += st[v].size();
}
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    rep(i,1,n+1)
        cin >> ans[i];
    cin >> s;
    s = '0'+s;
    rep(i,1,n){
        int u,v;
        cin >> v >> u;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0);
    int mx = 0,t = 0;
    rep(i,1,n+1){
        if (ans[i] > mx){
            mx = ans[i];
            t = 1;
        }
        else if (ans[i] == mx)
            t++;
    }
    cout << mx << endl << t;
}