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

const int maxn = 1123;

int n, m, a[maxn][maxn], r[maxn][maxn][2], to[maxn][maxn][2];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) FOR(j, 1, m) scanf("%d", &a[i][j]);
  FOR(i, 1, n) {
    map<int, vector<int>> now;
    FOR(j, 1, m) now[a[i][j]].eb(j);
    int cnt = 0;
    for (const auto &it : now) {
      cnt++;
      for (auto j : it._2) r[i][j][0] = cnt;
    }
    FOR(j, 1, m) to[i][j][0] = int(now.size()) - r[i][j][0];
  }
  FOR(j, 1, m) {
    map<int, vector<int>> now;
    FOR(i, 1, n) now[a[i][j]].eb(i);
    int cnt = 0;
    for (const auto &it : now) {
      cnt++;
      for (auto i : it._2) r[i][j][1] = cnt;
    }
    FOR(i, 1, n) to[i][j][1] = int(now.size()) - r[i][j][1];
  }
  FOR(i, 1, n) {
    FOR(j, 1, m) printf("%d ", max(r[i][j][0], r[i][j][1]) + max(to[i][j][0], to[i][j][1]));
    putchar('\n');
  }
}