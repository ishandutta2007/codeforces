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

const int maxm = 112345;

int n, m;
pii blks[maxm];

int main() {
  scanf("%d%d", &n, &m);
  REP(i, m) scanf("%d%d", &blks[i]._1, &blks[i]._2);
  sort(blks, blks + m);
  vector<pii> now, nxt;
  now.eb(1, 1);
  int j = 0, px = 0;
  while (j < m) {
    if (blks[j]._1 != px + 1 && !now.empty()) {
      int lo = now[0]._1;
      now = {mp(lo, n)};
    }
    int nj = j;
    while (nj < m && blks[nj]._1 == blks[j]._1) nj++;
    nxt.clear();
    int last = 1, k = 0;
    FOR(i, j, nj) {
      int en = i < nj ? blks[i]._2 : n + 1;
      while (k < now.size() && now[k]._2 < last) k++;
      if (k < now.size() && max(last, now[k]._1) < en) nxt.eb(max(last, now[k]._1), en - 1);
      last = blks[i]._2 + 1;
    }
    now = nxt;
    px = blks[j]._1;
    j = nj;
  }
  printf("%d", !now.empty() && (px < n || now.back()._2 == n) ? 2 * n - 2 : -1);
}