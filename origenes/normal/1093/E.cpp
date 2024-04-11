#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxn = 212345;

ordered_set<int> fen[maxn];

int n, q;
int a[maxn], b[maxn], ia[maxn], ib[maxn];

inline int lowbit(int x) {
  return x & -x;
}

void add(int x, int d) {
  while (x <= n) {
    fen[x].insert(d);
    x += lowbit(x);
  }
}

void del(int x, int d) {
  while (x <= n) {
    fen[x].erase(d);
    x += lowbit(x);
  }
}

int query(int x, int lo, int hi) {
  int ret = 0;
  while (x > 0) {
    ret += fen[x].order_of_key(hi + 1) - fen[x].order_of_key(lo);
    x -= lowbit(x);
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &q);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    ia[a[i]] = i;
  }
  FOR(i, 1, n) {
    scanf("%d", b + i);
    ib[b[i]] = i;
  }
  FOR(i, 1, n) {
    a[ia[i]] = ib[i];
    add(ia[i], a[ia[i]]);
  }
  while (q--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int l, r, x, y;
      scanf("%d%d%d%d", &l, &r, &x, &y);
      printf("%d\n", query(r, x, y) - query(l - 1, x, y));
    } else {
      int x, y;
      scanf("%d%d", &x, &y);
      swap(b[x], b[y]);
      x = b[x], y = b[y];
      swap(ib[x], ib[y]);
      del(ia[x], a[ia[x]]);
      del(ia[y], a[ia[y]]);
      swap(a[ia[x]], a[ia[y]]);
      add(ia[x], a[ia[x]]);
      add(ia[y], a[ia[y]]);
    }
  }
}