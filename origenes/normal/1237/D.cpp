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

int n, a[maxn], nxt[maxn], en[maxn], ans[maxn], bits[maxn];
int st[maxn][20];

int query(int l, int r) {
  int k = bits[r - l + 1];
  return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, n + 1, n + n) a[i] = a[i - n];
  int xx = 0;
  map<int, int> fi;
  FOR(i, 1, 2 * n) {
    st[i][0] = a[i];
    if (!fi.count(a[i])) fi[a[i]] = i;
    while (1 << xx + 1 <= i) xx++;
    bits[i] = xx;
  }
  FOR(j, 1, 19) for (int i = 1; i + (1 << j) - 1 <= n + n; i++)
    st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
  stack<int> s;
  FOR(i, 1, 2 * n) {
    while (!s.empty() && a[s.top()] < a[i]) {
      nxt[s.top()] = i;
      s.pop();
    }
    s.emplace(i);
  }
  while (!s.empty()) {
    nxt[s.top()] = 2 * n + 1;
    s.pop();
  }
  FOR(i, 1, 2 * n) {
    int lo = i, hi = nxt[i] - 1;
    while (lo < hi) {
      int mi = lo + hi + 1 >> 1;
      if (query(lo, mi) * 2 < a[i]) hi = mi - 1;
      else lo = mi;
    }
    en[i] = lo == nxt[i] - 1 ? nxt[i] : lo;
  }
  ans[2 * n + 1] = -1;
  priority_queue<pii> q;
  FOR(i, 1, 2 * n) q.emplace(a[i], -i);
  while (!q.empty()) {
    auto now = q.top(); q.pop();
    int i = -now._2;
//    BUG(fi[now._1]);
    if (en[i] >= nxt[i]) {
      if (i != fi[now._1] && nxt[i] == 2 * n + 1) {
        if (ans[fi[now._1]] == -1) ans[i] = -1;
        else ans[i] = ans[fi[now._1]] + n;
      }
      else ans[i] = ans[nxt[i]];
    }
    else ans[i] = en[i];
  }
  FOR(i, 1, n) if (ans[i] != -1) ans[i] = ans[i] - i + 1;
  FOR(i, 1, n) printf("%d ", ans[i]);
}