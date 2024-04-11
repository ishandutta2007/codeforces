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

const int maxc = 512345;

int n, m;
int st[maxc][19];

int main() {
  scanf("%d%d", &n, &m);
  vector<pii> tab(n);
  REP(i, n) scanf("%d%d", &tab[i]._1, &tab[i]._2);
  sort(all(tab), [&] (pii a, pii b) { return a._1 != b._1 ? a._1 < b._1 : a._2 > b._2; });
  vector<int> l, r;
  REP(i, n) {
    int j;
    for (j = i + 1; j < n; j++) if (tab[j]._2 > tab[i]._2) break;
    j--;
    l.eb(tab[i]._1); r.eb(tab[i]._2);
    i = j;
  }
  n = l.size();
  int j = 0;
  l.eb(5e5 + 10); r.eb(5e5 + 10);
  l.eb(5e5 + 10); r.eb(5e5 + 10);
  REP(i, 500001) {
    while (i >= l[j + 1]) j++;
    if (i > r[j]) j++;
    if (i < l[j]) {
      st[i][0] = -1;
      continue;
    }
    st[i][0] = r[j];
  }
  FOR(j, 1, 18) REP(i, 500001) {
    if (st[i][j - 1] == -1) st[i][j] = -1;
    else st[i][j] = max(st[st[i][j - 1]][j - 1], st[i][j - 1]);
  }
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (st[x][18] == -1 || st[x][18] < y) {
      puts("-1");
      continue;
    }
    int ans = 0;
    ROF(j, 17, 0) if (st[x][j] < y) {
        ans += 1 << j;
        x = st[x][j];
      }
    if (x < y) ans++;
    printf("%d\n", ans);
  }
}