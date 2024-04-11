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

int ans[maxn], pre[maxn], fen[maxn];
int n, q;
vector<int> poly[maxn];
vector<pii> qs[maxn];
pii pts[maxn];

inline int lowbit(int x) {
  return x & -x;
}

void add(int x, int d) {
  while (x <= n) {
    fen[x] += d;
    x += lowbit(x);
  }
}

int query(int x) {
  int ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

int query(int l, int r) {
  return query(r) - query(l - 1);
}

int main() {
  scanf("%d", &n);
  map<pii, int> mmap;
  FOR(i, 1, n) {
    int k;
    scanf("%d", &k);
    REP(j, k) scanf("%d%d", &pts[j]._1, &pts[j]._2);
    poly[i].resize(k);
    REP(j, k) {
      pii now = {pts[(j + 1) % k]._1 - pts[j]._1, pts[(j + 1) % k]._2 - pts[j]._2};
      int g = abs(__gcd(now._1, now._2));
      now._1 /= g, now._2 /= g;
      if (!mmap.count(now)) mmap[now] = mmap.size() + 1;
      poly[i][j] = mmap[now];
    }
  }
  scanf("%d", &q);
  FOR(i, 1, q) {
    int l, r;
    scanf("%d%d", &l, &r);
    qs[r].eb(i, l);
  }
  FOR(i, 1, n) {
    for (auto x : poly[i]) {
      if (pre[x]) add(pre[x], -1);
      add(i, 1);
      pre[x] = i;
    }
    for (auto _ : qs[i]) {
      int id = _._1, j = _._2;
      ans[id] = query(j, i);
    }
  }
  FOR(i, 1, q) printf("%d\n", ans[i]);
}