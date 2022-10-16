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

const int maxn = 51234;

int n, m, q;
bool on[maxn];
int cnt[maxn];
set<int> G[maxn];
char op[5];

void Union(int x, int y) {
  if (G[x].size() < G[y].size()) swap(x, y);
  G[y].emplace(x);
  cnt[x] += on[y];
}

int main() {
  scanf("%d%d%d", &n, &m, &q);
  int o; scanf("%d", &o);
  while (o--) {
    int x; scanf("%d", &x);
    on[x] = true;
  }
  while (m--) {
    int x, y; scanf("%d%d", &x, &y);
    Union(x, y);
  }
  while (q--) {
    scanf("%s", op);
    if (op[0] == 'O') {
      int x; scanf("%d", &x);
      on[x] = true;
      for (auto y : G[x]) cnt[y]++;
    } else if (op[0] == 'F') {
      int x; scanf("%d", &x);
      on[x] = false;
      for (auto y : G[x]) cnt[y]--;
    } else if (op[0] == 'A') {
      int x, y; scanf("%d%d", &x, &y);
      Union(x, y);
    } else if (op[0] == 'D') {
      int x, y; scanf("%d%d", &x, &y);
      if (G[x].count(y)) {
        G[x].erase(y);
        cnt[y] -= on[x];
      } else {
        G[y].erase(x);
        cnt[x] -= on[y];
      }
    } else {
      int x; scanf("%d", &x);
      int ans = cnt[x];
      for (auto y : G[x]) ans += on[y];
      printf("%d\n", ans);
    }
  }
}