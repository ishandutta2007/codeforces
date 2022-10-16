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

const int maxn = 112345;

ll s;
int n, cnt[maxn], deg[maxn];

bool check(int k) {
  reset(cnt, 0);
  reset(deg, 0);
  int i = 2, dep = 0;
  ll now = 1, to = s - n;
  while (i <= n) {
    now *= k;
    dep++;
    FOR(j, 1, now) {
      if (i > n) break;
      deg[i] = dep;
      cnt[dep]++;
      to -= dep;
      i++;
    }
  }
  if (to < 0) return false;
  i = n;
  while (to) {
    dep++;
    if (cnt[deg[i]] == 1) i--;
    now = min(to, ll(dep - deg[i]));
    cnt[deg[i]]--;
    deg[i] += now;
    cnt[deg[i]]++;
    to -= now;
    i--;
  }
  return true;
}

int main() {
  scanf("%d%lld", &n, &s);
  if (s < 2 * n - 1 || s > ll(n) * (n + 1) / 2) {
    puts("No");
    return 0;
  }
  int lo = 1, hi = n;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  check(hi);
  puts("Yes");
  int now = 1;
  deg[now] = 0;
  sort(deg + 2, deg + n + 1);
  reset(cnt, 0);
  FOR(i, 2, n) {
    while (deg[now] != deg[i] - 1 || cnt[now] == hi) now++;
    printf("%d ", now);
    cnt[now]++;
  }
}