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

int n, a[maxn], f[maxn];
map<int, int> mmap[maxn];

void solve() {
  scanf("%d", &n);
  mmap[0].clear();
  FOR(i, 1, n) {
    scanf("%d", a + i);
    mmap[i].clear();
  }
  ll ans = 0;
  fill(f + 1, f + n + 1, 0);
  FOR(i, 1, n) {
    int j = -1;
    if (mmap[i - 1].count(a[i])) {
      j = mmap[i - 1][a[i]];
      if (j > 0) swap(mmap[i], mmap[j - 1]);
    }
    mmap[i][a[i]] = i;
    if (j > 0) f[i] = f[j - 1] + 1;
    ans += f[i];
  }
  printf("%lld\n", ans);
}

int main() {
  int q; scanf("%d", &q);
  while (q--) solve();
}