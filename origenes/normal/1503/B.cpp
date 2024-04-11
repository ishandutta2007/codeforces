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

int main() {
  int n; cin >> n;
  vector<pii> p[2];
  FOR(i, 1, n) FOR(j, 1, n) p[(i + j) % 2].eb(i, j);
  vector<int> c(3, -1), used(3);
  REP(i, sqr(n)) {
    int ban; cin >> ban;
    int j = 0;
    for (; j < 2; j++) {
      if (ban == c[j]) continue;
      if (c[j] == -1) REP(k, 3) if (!used[k] && ban != k + 1) {
        used[k] = 1;
        c[j] = k + 1;
        break;
      }
      break;
    }
    if (!p[j].empty()) {
      cout << c[j] << ' ' << p[j].back()._1 << ' ' << p[j].back()._2 << endl;
      p[j].pop_back();
      continue;
    }
    if (c[1 - j] == -1) {
      REP(k, 3) if (!used[k] && ban != k + 1) {
        used[k] = 1;
        c[1 - j] = k + 1;
        break;
      }
    }
    if (c[2] == -1) {
      REP(k, 3) if (!used[k] && ban != k + 1) {
        used[k] = 1;
        c[2] = k + 1;
        break;
      }
    }
    int other = 1 - j;
    if (ban == c[other]) other = 2;
    assert(ban != c[other]);
    cout << c[other] << ' ' << p[1 - j].back()._1 << ' ' << p[1 - j].back()._2 << endl;
    p[1 - j].pop_back();
  }
}