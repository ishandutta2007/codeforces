 
// Problem : F. Vicky's Delivery Service
// Contest : Codeforces - Codeforces Round #561 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1166/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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
 
int lim, offset;
map<int, int> fa[400 * 1000 + 10];
 
void add(int x, int y) {
  for (int i = x; i <= lim; i += (i & -i))
    for (int j = y; j <= lim; j += (j & -j)) ++fa[i][j];
}
 
int query(int x, int y) {
  int sum = 0;
  for (int i = x; i > 0; i -= (i & -i))
    for (int j = y; j > 0; j -= (j & -j)) sum += fa[i][j];
  return sum;
}
 
int main() {
    fio;
 
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1, 0), b(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    a[i] = (x <= m) + a[i - 1];
    b[i] = (x >= m) + b[i - 1];
  }
 
  offset = n + 3;
  lim = offset + n + 3;
 
  ll res = 0;
  for (int i = 0; i <= n; ++i) {
    int x = offset + 2 * a[i] - i - 1;
    int y = offset + 2 * b[i] - i - 1;
    res += query(x, y - 1);
    add(x, y);
  }
 
  cout << res;
}