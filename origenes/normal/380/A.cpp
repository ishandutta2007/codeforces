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

const int maxn = 212345;

int n, m;
int a[maxn], l[maxn], c[maxn];
ll q[maxn];

int main() {
  scanf("%d", &m);
  ll len = 0;
  FOR(i, 1, m) {
    int op;
    scanf("%d", &op);
    if (op == 1) scanf("%d", c + i);
    else scanf("%d%d", l + i, c + i);
  }
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%lld", q + i);
    q[i]--;
  }
  vector<pii> tab;
  FOR(i, 1, m) {
    if (l[i] == 0) {
      tab.eb(1, -c[i]);
      if (len < 1e5) a[len] = c[i];
      len++;
    } else {
      while (c[i] && len < 1e5) {
        REP(j, l[i]) tab.eb(1, -a[j]), a[len++] = a[j];
        c[i]--;
      }
      if (c[i]) {
        tab.eb(c[i], l[i]);
        len += c[i] * l[i];
      }
    }
  }
  int j = 0;
  ll x = 0;
  FOR(i, 1, n) {
    auto length = [&](int j) -> int {
      if (tab[j]._2 < 0) return 1;
      return tab[j]._1 * tab[j]._2;
    };
    while (j < tab.size() && q[i] >= x + length(j)) x += length(j), j++;
    if (tab[j]._2 < 0) printf("%d ", -tab[j]._2);
    else {
      ll px = x - length(j);
      printf("%d ", a[(q[i] - px) % tab[j]._2]);
    }
  }
}