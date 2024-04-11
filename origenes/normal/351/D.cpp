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

const int maxn = 112345;

int b[maxn], last[maxn], pre[maxn], nxt[maxn], till[maxn], cnt[maxn], f[maxn], g[maxn];
bool good[maxn];
int m, q;
vector<pii> query[maxn];

inline int lowbit(int x) {
  return x & -x;
}

void add(int *fen, int x, int d) {
  if (!x) return;
  while (x <= m) {
    fen[x] += d;
    x += lowbit(x);
  }
}

int sum(const int *fen, int x) {
  int ret = 0;
  while (x) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

int main() {
  scanf("%d", &m);
  FOR(i, 1, m) scanf("%d", b + i);
  FOR(i, 1, m) {
    pre[i] = last[b[i]];
    last[b[i]] = i;
  }
  fill(last, last + maxn, m + 1);
  ROF(i, m, 1) {
    nxt[i] = last[b[i]];
    last[b[i]] = i;
  }
  FOR(i, 1, m) {
    if (!pre[i] || !pre[pre[i]]) till[i] = 1;
    else {
      if (i - pre[i] == pre[i] - pre[pre[i]]) till[i] = till[pre[i]];
      else till[i] = pre[pre[i]] + 1;
    }
  }
  scanf("%d", &q);
  FOR(i, 1, q) {
    int l, r;
    scanf("%d%d", &l, &r);
    query[r].eb(l, i);
  }
  FOR(i, 1, m) {
    if (pre[i]) {
      add(f, pre[i], -1);
      add(g, pre[i], -1);
      add(g, till[pre[i]] - 1, 1);
    }
    add(f, i, 1);
    add(g, i, 1);
    add(g, till[i] - 1, -1);
    for (auto x : query[i]) {
      int j = x._1, id = x._2;
      cnt[id] = sum(f, i) - sum(f, j - 1);
      good[id] = sum(g, i) - sum(g, j - 1) > 0;
    }
  }
  FOR(i, 1, q) printf("%d\n", cnt[i] + !good[i]);
}