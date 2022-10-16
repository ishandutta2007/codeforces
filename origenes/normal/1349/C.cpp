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

const int maxn = 1123;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

char s[maxn][maxn];
int n, m, t;
int f[maxn][maxn];

bool check(int x, int y) {
  REP(i, 4) {
    int nx = x + dx[i], ny = y + dy[i];
    if (s[x][y] == s[nx][ny]) return true;
  }
  return false;
}

int main() {
  scanf("%d%d%d", &n, &m, &t);
  FOR(i, 1, n) scanf("%s", s[i] + 1);
  reset(f, 0x3f);
  queue<pii> q;
  FOR(i, 1, n) FOR(j, 1, m) if (check(i, j)) {
    f[i][j] = 0;
    q.emplace(i, j);
  }
  while (!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    REP(i, 4) {
      int nx = x + dx[i], ny = y + dy[i];
      if (1 <= nx && nx <= n && 1 <= ny && ny <= m && f[nx][ny] > f[x][y] + 1) {
        f[nx][ny] = f[x][y] + 1;
        q.emplace(nx, ny);
      }
    }
  }
  while (t--) {
    int x, y;
    ll p;
    scanf("%d%d%lld", &x, &y, &p);
    if (f[x][y] > 5e8) printf("%c\n", s[x][y]);
    else {
      int ini = s[x][y] - '0';
      if (p > f[x][y]) ini = ini ^ ((p - f[x][y]) & 1);
      printf("%d\n", ini);
    }
  }
}