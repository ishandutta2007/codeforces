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

const int maxn = 2123;

int T, n, m;
char mat[maxn][maxn], G[maxn][maxn];
vector<pii> tab[26], ans[26];

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%s", mat[i] + 1);
    FOR(i, 1, n) FOR(j, 1, m) G[i][j] = '.';
    REP(i, 26) {
      tab[i].clear();
      ans[i].clear();
    }
    int occ = -1;
    FOR(i, 1, n) FOR(j, 1, m) if (islower(mat[i][j])) {
      int idx = mat[i][j] - 'a';
      chkmax(occ, idx);
      tab[idx].eb(i, j);
    }
    if (occ == -1) {
      puts("YES\n0");
      continue;
    }
    auto fi = tab[occ].front();
    bool good = true;
    ROF(idx, occ, 0) {
      sort(all(tab[idx]));
      if (tab[idx].empty()) ans[idx] = {fi, fi};
      else if (tab[idx].size() == 1) {
        ans[idx] = {tab[idx][0], tab[idx][0]};
      } else {
        if (tab[idx][0]._1 != tab[idx].back()._1 && tab[idx][0]._2 != tab[idx].back()._2) {
          good = false;
          break;
        }
        ans[idx] = {tab[idx][0], tab[idx].back()};
      }
    }
    if (!good) {
      puts("NO");
      continue;
    }
    REP(i, occ + 1) {
      int x1 = ans[i][0]._1, y1 = ans[i][0]._2, x2 = ans[i][1]._1, y2 = ans[i][1]._2;
      if (ans[i][0] == ans[i][1]) {
        G[x1][y1] = i + 'a';
        continue;
      }
      if (x1 != x2) {
        FOR(j, x1, x2) G[j][y1] = i + 'a';
      } else {
        FOR(j, y1, y2) G[x1][j] = i + 'a';
      }
    }
    FOR(i, 1, n) FOR(j, 1, m) if (mat[i][j] != G[i][j]) {
      good = false;
      break;
    }
    puts(good ? "YES" : "NO");
    if (good) {
      printf("%d\n", occ + 1);
      REP(i, occ + 1) printf("%d %d %d %d\n", ans[i][0]._1, ans[i][0]._2, ans[i][1]._1, ans[i][1]._2);
    }
  }
}