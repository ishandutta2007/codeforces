 
// Problem : D. Help Monks
// Contest : Codeforces - Codeforces Beta Round #78 (Div. 1 Only)
// URL : https://codeforces.com/problemset/problem/98/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
typedef pair<int, int> P;
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int INF = 0x3f3f3f3f, maxn = 80005;
int n, sz[maxn], fa[maxn];
vector<int> g[maxn];
void dfs(int u, int f){
  sz[u] = 1;
  fa[u] = f;
  for(int i = 0; i < g[u].size(); i++){
    int v = g[u][i];
    if(v == f) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}
ll C(int n){
  return (ll)n * (n - 1) / 2;
}
int main(){
    fio;
    cin>>n;
  for(int i = 1; i < n; i++){
    int u, v;
    cin>>u>>v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  ll res = C(n) * C(n);
  
  for(int u = 1; u <= n; u++){
    ll num1 = C(n), num2 = C(sz[u]);
    for(int i = 0; i < g[u].size(); i++){
      int v = g[u][i];
      if(v != fa[u]) num1 -= C(sz[v]),num2 -= C(sz[v]);
      else num1 -= C(n - sz[u]);
    }
    res -= (2ll * num1 * num2 - num2 * num2);
  }
  cout<<res;
}