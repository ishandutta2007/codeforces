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
#define ii pair<int,int>
#define iii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
 
const int N = 2e3 + 5;
 
vector <int> adj[N],points;
int n,x[N],y[N],sub[N],ans[N];
double ang[N];
bool vis[N];
 
int dfs(int cur,int back) {
  sub[cur] = 1;
  for (int i : adj[cur])
    if (i != back && vis[i] == false)
      sub[cur] += dfs(i,cur);
  return sub[cur];
}
 
void solve(int root,vector <int> points) {
  sort(points.begin(),points.end(), [&](int a,int b) {
    if (x[a] == x[b])
      return y[a] < y[b];
    return x[a] < x[b];
  });
  ans[points[0]] = root;
  for (auto i : points)
    ang[i] = atan2(y[i] - y[points[0]],x[i] - x[points[0]]);
  sort(points.begin() + 1,points.end(), [&](int a,int b) {
    return ang[a] < ang[b]; 
  });
  dfs(root,-1);
  vis[root] = true;
  for (int i : adj[root]) {
    if (vis[i] == false) {
      vector <int> temp;
      for (int j = 0 ; j < sub[i] ; j++) {
        temp.push_back(points.back());
        points.pop_back();
      }
      solve(i,temp);
    }
  }
}
 
int main() {
    fio;
  cin >> n;
  for (int i = 1 ; i < n ; i++) {
    int u,v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1 ; i <= n ; i++) {
    cin >> x[i] >> y[i];
    points.push_back(i);
  }
  solve(1,points);
  for (int i = 1 ; i <= n ; i++)
    cout << ans[i] << " ";
}