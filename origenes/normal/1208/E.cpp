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

const int maxn = 1123456;

int n, w;
ll f[maxn];
vector<int> a[maxn];

inline void add(int l, int r, int d) {
  if (l > r) return;
  f[l] += d;
  f[r + 1] -= d;
}

int main() {
  scanf("%d%d", &n, &w);
  FOR(i, 1, n) {
    int l;
    scanf("%d", &l);
    a[i].resize(l + 2);
    FOR(j, 1, l) scanf("%d", &a[i][j]);
  }
  FOR(i, 1, n) {
    int m = a[i].size() - 2, j;
    deque<int> q;
    q.eb(0);
    for (j = 1; j <= m; j++) {
      int l = j - w + m, r = j;
      while (!q.empty() && q.front() < l) q.pop_front();
      while (!q.empty() && a[i][q.back()] <= a[i][r]) q.pop_back();
      q.eb(r);
      add(j, j, a[i][q.front()]);
    }
    int nj = w - m;
    add(j, nj, a[i][q.front()]);
    chkmax(j, nj + 1);
    for (; j <= w; j++) {
      int l = j - w + m, r = min(j + w - m, m + 1);
      while (!q.empty() && q.front() < l) q.pop_front();
      while (!q.empty() && a[i][q.back()] <= a[i][r]) q.pop_back();
      q.eb(r);
      add(j, j, a[i][q.front()]);
    }
  }
  ll now = 0;
  FOR(i, 1, w) {
    now += f[i];
    printf("%lld ", now);
  }
}