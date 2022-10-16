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

vector<int> u[50];

int t, m, f[25][50], s[25];
ll n, ans[6], pw[20];

void init() {
  int tab[] = {0, 4, 7};
  REP(i, 3) REP(j, 3) REP(k, 3) REP(x, 3) REP(y, 3) REP(z, 3) {
    int now = tab[i] + tab[j] + tab[k] + tab[x] + tab[y] + tab[z];
    if (u[now].empty()) u[now] = {tab[i], tab[j], tab[k], tab[x], tab[y], tab[z]};
  }
  pw[0] = 1;
  FOR(i, 1, 18) pw[i] = pw[i - 1] * 10;
}

void dfs(int pos, int rem) {
  int now = rem * 10 + s[pos];
  if (now > 46) return;
  REP(i, 5) {
    int need = now - i;
    if (need < 0) continue;
    if (!u[need].empty() && f[pos + 1][i] == -1) {
      f[pos + 1][i] = rem;
      if (pos < m) dfs(pos + 1, i);
    }
  }
}

int main() {
  init();
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    m = 0;
    while (n) {
      s[++m] = n % 10;
      n /= 10;
    }
    reverse(s + 1, s + m + 1);
    reset(f, -1);
    dfs(1, 0);
    if (f[m + 1][0] == -1) {
      puts("-1");
      continue;
    }
    reset(ans, 0);
    int x = 0;
    ROF(i, m + 1, 2) {
      int d = f[i][x] * 10 - x + s[i - 1];
      REP(j, 6) ans[j] += u[d][j] * pw[m + 1 - i];
      x = f[i][x];
    }
    REP(i, 6) printf("%lld ", ans[i]);
    puts("");
  }
}