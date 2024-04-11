
// Problem : E. Periodical Numbers
// Contest : Codeforces - Codeforces Round #132 (Div. 2)
// URL : https://codeforces.com/problemset/problem/215/E
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
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
#define sz(x) ((int)(x).size())
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
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int maxn = 64 + 7;
vector<int> g[maxn];
ll res[maxn];
ll l, r;
 
void init() {
  for (int i = 1; i <= 64; i++) {
    for (int j = 1; j < i; j++) {
      if (i % j == 0) 
        g[i].push_back(j);
    }
  }
}
 
ll solve(ll n) {
  if(n <= 1)
    return 0;
  int len = 0;
  while(((ll) 1 << len) <= n) 
    ++len;
  ll sum = solve(((ll) 1 << (len - 1)) - 1);
  int sz = g[len].size();
  memset(res, 0, sizeof(res));
  for (int i = 0; i < sz; i++) {
    int v = g[len][i];
    ll a = n >> (len - v), maxv = 0;
    for(int j = 0; j < len / v; j++) {
      maxv = ((ll) maxv << (v)) | a;
    }
    res[v] = (maxv <= n) + (a - ((ll) 1 << (v - 1)));
    int subsz = g[v].size();
    for(int j = 0; j < subsz; j++) 
      res[v] -= res[g[v][j]]; 
    sum += res[v];
  }
  return sum;
}
 
int main() {
  init();
  cin>>l>>r;
  cout<<solve(r) - solve(l - 1)<<endl;
}