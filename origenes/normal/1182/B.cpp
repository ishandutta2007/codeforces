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

const int maxn = 512;

int h, w;
char s[maxn][maxn];

inline bool check(int i, int j) {
  return i > 0 && i <= h && j > 0 && j <= w && s[i][j] == '*';
}

void go(int x, int y, int dx, int dy) {
  while (x > 0 && x <= h && y > 0 && y <= w && s[x][y] == '*') {
    s[x][y] = '.';
    x += dx, y += dy;
  }
}

int main() {
  scanf("%d%d", &h, &w);
  FOR(i, 1, h) scanf("%s", s[i] + 1);
  bool good = false;
  pii o;
  FOR(i, 1, h) FOR(j, 1, w) if (s[i][j] == '*') {
    if (check(i - 1, j) && check(i + 1, j) && check(i, j - 1) && check(i, j + 1)) {
      good = true;
      o = {i, j};
      goto label;
    }
  }
  label:
  if (!good) {
    puts("NO");
    return 0;
  }
  s[o._1][o._2] = '.';
  go(o._1 + 1, o._2, 1, 0);
  go(o._1 - 1, o._2, -1, 0);
  go(o._1, o._2 + 1, 0, 1);
  go(o._1, o._2 - 1, 0, -1);
  FOR(i, 1, h) FOR(j, 1, w) if (s[i][j] == '*') {
    puts("NO");
    return 0;
  }
  puts("YES");
}