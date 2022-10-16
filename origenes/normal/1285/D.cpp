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

inline bool test(int a, int j) {
  return (a & (1 << j)) > 0;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  REP(i, n) scanf("%d", &a[i]);
  sort(all(a));
  uni(a);
  n = a.size();
  int ans = 1 << 30;
  REP(i, n) {
    int l = 0, r = n - 1, now = 0;
    ROF(j, 29, 0) {
      if (l == r) break;
      if (test(a[l], j) == test(a[r], j)) continue;
      if (test(a[l], j) == test(a[i], j)) {
        int lo = i, hi = r - 1;
        while (lo < hi) {
          int mi = lo + hi + 1 >> 1;
          if (test(a[mi], j) == test(a[i], j)) lo = mi;
          else hi = mi - 1;
        }
        r = lo;
      } else {
        int lo = l + 1, hi = i;
        while (lo < hi) {
          int mi = lo + hi >> 1;
          if (test(a[mi], j) == test(a[i], j)) hi = mi;
          else lo = mi + 1;
        }
        l = lo;
      }
      now |= (1 << j);
    }
    chkmin(ans, now);
  }
  printf("%d", ans);
}