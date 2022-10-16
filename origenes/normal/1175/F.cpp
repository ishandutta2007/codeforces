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

const int maxn = 312345;

int n, ans;
int st[maxn][19], nxt[maxn], a[maxn], bit[maxn], now[maxn];

int rmq(int l, int r) {
  int k = bit[r - l + 1];
  return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  ROF(i, n, 1) {
    st[i][0] = a[i];
    nxt[i] = now[a[i]] ? now[a[i]] : n + 1;
    if (i != n) chkmin(nxt[i], nxt[i + 1]);
    now[a[i]] = i;
  }
  {
    int j = 0;
    FOR(i, 1, n) {
      while (1 << j <= i) j++;
      bit[i] = j - 1;
    }
  }
  FOR(j, 1, 18) FOR(i, 1, n - (1 << j) + 1) st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
  FOR(i, 1, n) FOR(j, i, nxt[i] - 1) {
    while (j < nxt[i] && rmq(i, j) > j - i + 1) j = i + rmq(i, j) - 1;
    if (j < nxt[i]) ans++;
  }
  printf("%d", ans);
}