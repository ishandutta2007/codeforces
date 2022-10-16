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

int n, c[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", c + i);
  pii l[2], r[2];
  l[0] = {c[1], 1};
  FOR(i, 2, n) if (c[i] != c[1]) {
    l[1] = {c[i], i};
    break;
  }
  r[0] = {c[n], n};
  ROF(i, n - 1, 1) if (c[i] != c[n]) {
    r[1] = {c[i], i};
    break;
  }
  int ans = 0;
  REP(i, 2) REP(j, 2) if (l[i]._1 != r[j]._1) {
    chkmax(ans, r[j]._2 - l[i]._2);
  }
  printf("%d", ans);
}