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

const int maxn = 112345;

set<pii> col[maxn], dia1[maxn], dia2[maxn];

int main() {
  int n, q, cnt = 0;
  scanf("%d%d", &n, &q);
  while (q--) {
    int r, c;
    scanf("%d%d", &r, &c);
    c += 5;
    if (col[c].count(mp(r, c))) {
      col[c].erase(mp(r, c));
      if (!col[c].empty()) cnt--;
      dia1[r + c].erase(mp(r, c));
      if (!dia1[r + c].empty()) cnt--;
      dia2[c - r].erase(mp(r, c));
      if (!dia2[c - r].empty()) cnt--;
    } else {
      col[c].emplace(r, c);
      if (col[c].size() == 2) cnt++;
      dia1[r + c].emplace(r, c);
      if (dia1[r + c].size() == 2) cnt++;
      dia2[c - r].emplace(r, c);
      if (dia2[c - r].size() == 2) cnt++;
    }
    puts(cnt == 0 ? "Yes" : "No");
  }
}