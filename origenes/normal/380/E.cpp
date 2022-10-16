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

pii b[maxn];
int n, pre[maxn], nxt[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", &b[i]._1);
    b[i]._2 = i;
  }
  sort(b + 1, b + n + 1);
  FOR(i, 1, n) nxt[i] = i + 1, pre[i] = i - 1;
  double ans = 0;
  FOR(i, 1, n) {
    int id = b[i]._2, lo = id, hi = id;
    double l = 0, r = 0, f = 1;
    REP(j, 60) {
      f /= 2;
      if (lo) {
        l += f * (lo - pre[lo]);
        lo = pre[lo];
      }
      if (hi <= n) {
        r += f * (nxt[hi] - hi);
        hi = nxt[hi];
      }
    }
    ans += 2 * b[i]._1 * l * r;
    nxt[pre[id]] = nxt[id];
    pre[nxt[id]] = pre[id];
  }
  printf("%.10lf", ans / sqr(double(n)));
}