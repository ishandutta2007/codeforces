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

const int maxn = 5123;
const int OFF = 5005;

int n;
vector<pii> h[2 * maxn], v[2 * maxn];

inline int lowbit(int x) {
  return x & -x;
}

void add(vector<int> &fen, int x, int d) {
  while (x < fen.size()) {
    fen[x] += d;
    x += lowbit(x);
  }
}

int sum(const vector<int> &fen, int x) {
  int ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  while (n--) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1 += OFF, y1 += OFF, x2 += OFF, y2 += OFF;
    if (x1 > x2) swap(x1, x2);
    if (y1 > y2) swap(y1, y2);
    if (x1 == x2) v[x1].eb(y1, y2);
    else h[y1].eb(x1, x2);
  }
  ll ans = 0;
  FOR(y, 1, 2 * OFF) for (auto now : h[y]) {
    int st = now._1, en = now._2;
    vector<int> fen(2 * maxn);
    vector<pii> out;
    FOR(x, st, en) for (auto cur : v[x]) if (cur._1 <= y && y <= cur._2) {
      out.eb(cur._2 + 1, x);
      add(fen, x, 1);
    }
    sort(all(out));
    int i = 0;
    FOR(hi, y + 1, 2 * OFF) {
      while (i < out.size() && out[i]._1 == hi) {
        add(fen, out[i]._2, -1);
        i++;
      }
      for (auto cur : h[hi]) {
        int s = sum(fen, cur._2) - sum(fen, cur._1 - 1);
        ans += s * ll(s - 1) / 2;
      }
    }
  }
  printf("%lld", ans);
}