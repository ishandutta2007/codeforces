#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 312345;

ll ans[30];

struct Trie {
  struct Node { int v = 0, l = -1, r = -1; };

  vector<Node> T;
  
  Trie() {
    T = vector<Node>{ Node() };
  }

  void insert(int a) {
    int u = 0;
    ROF(i, 29, 0) {
      int d = (a >> i) & 1;
      if (d == 0 && T[u].l == -1) {
        T[u].l = T.size();
        T.eb();
      } else if (d == 1 && T[u].r == -1) {
        T[u].r = T.size();
        T.eb();
      }
      if (d == 0) {
        T[T[u].l].v++;
        if (T[u].r != -1) ans[i] -= T[T[u].r].v;
        u = T[u].l;
      } else {
        T[T[u].r].v++;
        if (T[u].l != -1) ans[i] += T[T[u].l].v;
        u = T[u].r;
      }
    }
  }

  int add(int a) {
    int u = 0, ret = 0;
    ROF(i, 29, 0) {
      int d = (a >> i) & 1;
      if (d == 0 && T[u].l == -1) {
        T[u].l = T.size();
        T.eb();
      } else if (d == 1 && T[u].r == -1) {
        T[u].r = T.size();
        T.eb();
      }
      if (d == 1 && T[u].l != -1) ret += T[T[u].l].v;
      if (d) T[T[u].r].v++, u = T[u].r;
      else T[T[u].l].v++, u = T[u].l;
    }
    return ret;
  }
};

int n;
int a[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  Trie trie;
  ROF(i, n, 1) trie.insert(a[i]);
  int x = 0;
  REP(i, 30) if (ans[i] > 0) x |= 1 << i;
  FOR(i, 1, n) a[i] ^= x;
  ll val = 0;
  trie = Trie();
  ROF(i, n, 1) val += trie.add(a[i]);
  printf("%lld %d", val, x);
}