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

const int maxn = 1123456;

int n, q, tot;
int p[maxn], l[maxn], r[maxn], rec[maxn];
vector<int> ql[maxn], qr[maxn];

ll ans[maxn], s[maxn], fen[maxn];

inline int lowbit(int x) {
  return x & -x;
}

void add(int x, int d) {
  x++;
  while (x <= n) {
    fen[x] += d;
    x += lowbit(x);
  }
}

ll sum(int x) {
  ll ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &q);
  REP(i, n) scanf("%d", p + i);
  REP(i, q) scanf("%d", l + i);
  REP(i, q) {
    scanf("%d", r + i);
    l[i]--, r[i]--;
    ql[l[i]].eb(i);
    qr[r[i]].eb(i);
  }
  REP(i, n) {
    while (tot && p[rec[tot - 1]] < p[i]) {
      tot--;
      add(rec[tot], i - rec[tot] - 1);
    }
    rec[tot] = i;
    s[tot] = i + (tot ? s[tot - 1] : 0);
    tot++;
    for (int v : qr[i]) {
      ans[v] += sum(i + 1) - sum(l[v]);
      int u = lower_bound(rec, rec + tot, l[v]) - rec;
      ll now = s[tot - 1] - (u ? s[u - 1] : 0);
      ans[v] += ll(tot - u) * i - now;
    }
  }
  tot = 0;
  reset(fen, 0);
  ROF(i, n - 1, 0) {
    while (tot && p[-rec[tot - 1]] < p[i]) {
      tot--;
      add(-rec[tot], -rec[tot] - i - 1);
    }
    rec[tot] = -i;
    s[tot] = i + (tot ? s[tot - 1] : 0);
    tot++;
    for (int v : ql[i]) {
      ans[v] += sum(r[v] + 1) - sum(i);
      int u = lower_bound(rec, rec + tot, -r[v]) - rec;
      ll now = s[tot - 1] - (u ? s[u - 1] : 0);
      ans[v] -= ll(tot - u) * i - now;
    }
  }
  REP(i, q) printf("%lld ", ans[i] + r[i] - l[i] + 1);
}