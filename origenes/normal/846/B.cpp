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

const int maxn = 55;

int t[maxn];
int n, k, m, s;

int main() {
  scanf("%d%d%d", &n, &k, &m);
  FOR(i, 1, k) scanf("%d", t + i);
  FOR(i, 1, k) s += t[i];
  sort(t + 1, t + k + 1);
  int ans = 0;
  REP(i, n + 1) {
    if (s * i > m) continue;
    int rem = m - s * i, now = (k + 1) * i;
    FOR(j, 1, k) {
      int coeff = min(n - i, rem / t[j]);
      now += coeff;
      rem -= coeff * t[j];
    }
    chkmax(ans, now);
  }
  printf("%d", ans);
}