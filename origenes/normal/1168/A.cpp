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

int n, m;
int a[maxn], hi[maxn];

bool check(int upp) {
  int pre = 0;
  FOR(i, 1, n) {
    hi[i] = a[i] + upp;
    if (pre <= a[i]) {
      if (hi[i] < m) pre = a[i];
      else {
        if (hi[i] >= m && pre <= hi[i] - m) continue;
        pre = a[i];
      }
    } else {
      if (pre <= hi[i]) continue;
      return false;
    }
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", a + i);
  int l = 0, r = m - 1;
  while (l < r) {
    int mi = l + r >> 1;
    if (check(mi)) r = mi;
    else l = mi + 1;
  }
  printf("%d", l);
}