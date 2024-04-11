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

int a[maxn], b[maxn], n;

int check(int mi) {
  int rem = b[n] - mi;
  FOR(i, 1, n - 1) {
    int A = a[i], B = b[i];
    A -= min(A, rem);
    B -= A;
    if (B < 0) return -1;
    rem = B;
  }
  return rem + mi < a[n];
}

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) scanf("%d", b + i);
  int lo = 0, hi = b[n];
  while (lo <= hi) {
    int mi = lo + hi >> 1;
    int r = check(mi);
    if (r == 0) break;
    if (r > 0) lo = mi + 1;
    else hi = mi - 1;
  }
  puts(lo <= hi ? "YES" : "NO");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}