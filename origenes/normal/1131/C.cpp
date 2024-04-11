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

const int maxn = 112;

int n, a[maxn], ans[maxn];
bool vis[maxn];

bool check(int diff) {
  ans[1] = a[1];
  int pre = 1, now = 2, pos = 2;
  vis[1] = true;
  while (now < n) {
    while (now < n && a[now + 1] - a[pre] <= diff) now++;
    if (now == pre) return false;
    ans[pos] = a[now];
    pre = now;
    vis[now] = true;
    pos++;
  }
  ROF(i, n, 1) if (!vis[i]) {
      ans[pos] = a[i];
      if (ans[pos - 1] - ans[pos] > diff) return false;
      pos++;
    }
  return (ans[n] - ans[1]) <= diff;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  sort(a + 1, a + n + 1);
  int lo = 0, hi = 1e9;
  while (lo < hi) {
    int m = lo + hi >> 1;
    reset(vis, 0);
    if (check(m)) hi = m;
    else lo = m + 1;
  }
  reset(vis, 0);
  check(lo);
  FOR(i, 1, n) printf("%d ", ans[i]);
}