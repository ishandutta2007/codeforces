
// Problem : E. Neatness
// Contest : Codeforces - Codeforces Round #209 (Div. 2)
// URL : https://codeforces.com/contest/359/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)
 
/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
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
 
const int N = 4e6 + 5;
ll tree[N << 2][2], lazy[N << 2][2];
void propagate(int i, int l, int r, bool f) {
  if (!lazy[i][f]) return;
  tree[i][f] += lazy[i][f] * 1ll * (r - l + 1);
  if (l != r) lazy[i << 1][f] += lazy[i][f], lazy[i << 1 | 1][f] += lazy[i][f];
  lazy[i][f] = 0;
}
void update(int i, int l, int r, int a, int b, ll v, bool f) {
  propagate(i, l, r, f);
 
  if (l > b || r < a) return;
  if (l >= a && r <= b) {
    lazy[i][f] = v;
    return propagate(i, l, r, f);
  }
  int mid = (l + r) >> 1;
  update(i << 1, l, mid, a, b, v, f);
  update(i << 1 | 1, mid + 1, r, a, b, v, f);
  tree[i][f] = tree[i << 1][f] + tree[i << 1 | 1][f];
}
ll get(int i, int l, int r, int a, int b, bool f) {
  propagate(i, l, r, f);
  if (l > b || r < a) return 0;
  if (l >= a && r <= b) return tree[i][f];
  int mid = (l + r) >> 1;
  ll res = get(i << 1, l, mid, a, b, f) + get(i << 1 | 1, mid + 1, r, a, b, f);
  tree[i][f] = tree[i << 1][f] + tree[i << 1 | 1][f];
  return res;
}
int main() {
    fio;
  int n, m, q;
  cin >> n >> m >> q;
  while (q--) {
    int t;
    int x1, y1, x2, y2, v;
    cin >> t;
    cin >> x1 >> y1 >> x2 >> y2;
    if (!t) {
      cin >> v;
      update(1, 1, n, x1, x2, (y2 - y1 + 1) * 1ll * v, 0);
      update(1, 1, m, y1, y2, (x2 - x1 + 1) * 1ll * v, 1);
    } else {
      ll res = get(1, 1, n, x1, x2, 0);
      res -= get(1, 1, m, 1, y1 - 1, 1);
      res -= get(1, 1, m, y2 + 1, m, 1);
      cout << res << '\n';
    }
  }
}