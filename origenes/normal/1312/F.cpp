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

int f[maxn], g[maxn], h[maxn];
int n, x, y, z, p = -1;
ll a[maxn];

int mex(vector<int> v) {
  sort(all(v));
  uni(v);
  v.eb(maxn);
  for (int i = 0; ; i++) if (v[i] != i) return i;
}

int get(int *f, ll tar) {
  if (tar > 200) return f[(tar - 200) % p + 200];
  return f[tar];
}

void solve() {
  scanf("%d%d%d%d", &n, &x, &y, &z);
  FOR(i, 1, 300) {
    f[i] = mex({f[max(i - x, 0)], g[max(i - y, 0)], h[max(i - z, 0)]});
    g[i] = mex({f[max(i - x, 0)], h[max(i - z, 0)]});
    h[i] = mex({f[max(i - x, 0)], g[max(i - y, 0)]});
    bool good = i > 200;
    REP(j, 5) {
      good &= f[200 - j] == f[i - j];
      good &= g[200 - j] == g[i - j];
      good &= h[200 - j] == h[i - j];
    }
    if (good) {
      p = i;
      break;
    }
  }
  p -= 200;
  int sg = 0;
  FOR(i, 1, n) {
    scanf("%lld", a + i);
    sg ^= get(f, a[i]);
  }
  int ans = 0;
  FOR(i, 1, n) {
    sg ^= get(f, a[i]);
    if (!(sg ^ get(f, max(a[i] - x, 0LL)))) ans++;
    if (!(sg ^ get(g, max(a[i] - y, 0LL)))) ans++;
    if (!(sg ^ get(h, max(a[i] - z, 0LL)))) ans++;
    sg ^= get(f, a[i]);
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}