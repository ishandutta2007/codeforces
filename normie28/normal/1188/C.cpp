
// Problem : E. Vasya and Binary String
// Contest : Codeforces - Educational Codeforces Round 59 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1107/E
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
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//

const int A = 1e5 + 5, N = 1024, mod = 998244353;
 
int n, k;
int a[N];
int dp[N][N];
 
int add(int & x, int y) {
  x += y;
  if (x >= mod)
    x -= mod;
  return x;
}
 
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", a+i);
  sort(a, a+n);
  for (int i = 1; i <= n; ++i)
    dp[i][1] = i;
  int ans = 0, last = 0;
  for (int b = A / (k-1); b >= 0; --b) {
    for (int i = 0, j = 0; i < n; ++i) {
      while (j <= i && a[i] - a[j] >= b) ++j;
      for (int c = 2; c <= k; ++c) {
        dp[i+1][c] = dp[i][c];
        add(dp[i+1][c], dp[j][c-1]);
      }
    }
    int diff = dp[n][k];
    add(diff, mod - last);
    add(ans, diff * 1LL * b % mod);
    last = dp[n][k];
  }
  printf("%d\n", ans);
  return 0;
}