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

const int maxn = 512345;

int a[maxn], n, x;
ll d[maxn];

int main() {
  scanf("%d", &n);
  int m = (n + 1) / 2;
  FOR(i, 1, m) scanf("%d", a + i);
  scanf("%d", &x);
  ll s = 0;
  FOR(i, 1, m) {
    s += x - a[i];
    d[i] = min(d[i - 1], s);
  }
  s = 0;
  FOR(i, 1, m) s += a[i];
  FOR(i, m, n) {
    if (s + d[n - i] > 0) {
      printf("%d", i);
      return 0;
    }
    s += x;
  }
  puts("-1");
}