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

int n, a[maxn], st[maxn], last[maxn], fen[maxn];
vector<int> G[maxn];

int lowbit(int x) {
  return x & -x;
}

int query(int x) {
  int ret = 0;
  while (x) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

void add(int x, int d) {
  while (x <= n) {
    fen[x] += d;
    x += lowbit(x);
  }
}

void solve() {
  scanf("%d", &n);
  fill(st + 1, st + n + 1, n + 1);
  fill(last + 1, last + n + 1, 0);
  fill(fen + 1, fen + n + 1, 0);
  FOR(i, 1, n) G[i].clear();
  FOR(i, 1, n) {
    scanf("%d", a + i);
    chkmin(st[a[i]], i);
    chkmax(last[a[i]], i);
    G[a[i]].eb(i);
  }
  int ans = 0, cnt = 0, j = n, tot = 0;
  ROF(i, n, 1) if (st[i] <= n) {
    while (j) {
      if (st[j] > n) {
        j--;
        continue;
      }
      if (query(last[j])) break;
      for (auto u : G[j]) add(u, 1);
      j--;
      tot++;
    }
    chkmax(ans, tot);
    cnt++;
    for (auto u : G[i]) add(u, -1);
    tot--;
  }
  printf("%d\n", cnt - ans);
}

int main() {
  int q; scanf("%d", &q);
  while (q--) solve();
}