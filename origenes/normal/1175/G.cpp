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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 21234;
const int maxk = 112;
const int inf = 0x3f3f3f3f;

struct Node {
  int k, b, p;

  Node(int k, int b, int p) : k(k), b(b), p(p) {}
};

inline int f(pii coeff, int x) {
  return coeff._1 * x + coeff._2;
}

inline bool check(pii a, pii b, pii c) {
  double u = double(b._2 - a._2) / (a._1 - b._1);
  double v = double(b._2 - c._2) / (c._1 - b._1);
  return u <= v;
}

struct Hull {
  vector<pii> q;

  void add(int k, int b) {
    if (!q.empty() && q.back()._1 == k) {
      chkmin(b, q.back()._2);
      q.pop_back();
    }
    while (q.size() > 1 && !check(q[q.size() - 2], q.back(), {k, b})) q.pop_back();
    q.eb(k, b);
  }

  int query(int x) {
    if (q.empty()) return inf;
    int lo = 0, hi = q.size() - 1;
    while (lo < hi) {
      int mi = lo + hi >> 1;
      if (f(q[mi], x) > f(q[mi + 1], x)) lo = mi + 1;
      else hi = mi;
    }
    return f(q[lo], x);
  }
};

int n, k;
int a[maxn], dp[maxk][maxn], suf[maxn];

void solve(int lo, int hi, int lvl) {
  if (lo == hi) return;
  int mi = lo + hi >> 1;
  solve(lo, mi, lvl);
  solve(mi + 1, hi, lvl);
  int mmax = 0;
  vector<Node> pref;
  ROF(i, mi, lo) {
    if (dp[lvl - 1][i] != inf) pref.eb(mmax, dp[lvl - 1][i], i);
    chkmax(mmax, a[i]);
  }
  suf[mi] = 0;
  FOR(i, mi + 1, hi) suf[i] = max(suf[i - 1], a[i]);
  Hull hull;
  int j = pref.size();
  ROF(i, hi, mi + 1) {
    while (j && pref[j - 1].k >= suf[i]) {
      j--;
      hull.add(pref[j].k, pref[j].b - pref[j].p * pref[j].k);
    }
    chkmin(dp[lvl][i], hull.query(i));
  }
  hull = Hull();
  j = 0;
  FOR(i, mi + 1, hi) {
    while (j < pref.size() && pref[j].k < suf[i]) {
      hull.add(pref[j].p, pref[j].b);
      j++;
    }
    chkmin(dp[lvl][i], hull.query(-suf[i]) + i * suf[i]);
  }
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  reset(dp, 0x3f);
  dp[0][0] = 0;
  FOR(i, 1, k) solve(0, n, i);
  printf("%d", dp[k][n]);
}