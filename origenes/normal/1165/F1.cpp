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

const int maxn = 212345;

int n, m;
pii off[maxn];
int k[maxn];

bool check(int upp) {
  int used = 0;
  vector<int> need(n + 1), last(n + 1, -1);
  vector<vector<int>> lis(upp + 1, vector<int>());
  FOR(i, 1, n) need[i] = k[i];
  FOR(i, 1, m) {
    if (off[i]._1 > upp) break;
    last[off[i]._2] = off[i]._1;
  }
  FOR(i, 1, n) if (last[i] > 0) lis[last[i]].eb(i);
  FOR(i, 1, upp) if (!lis[i].empty()) {
    for (auto it : lis[i]) if (need[it]) {
      int have = i - used;
      if (have >= need[it]) {
        used += need[it];
        need[it] = 0;
      } else {
        need[it] -= have;
        used = i;
        break;
      }
    }
  }
  FOR(i, 1, n) if (need[i]) {
    if (need[i] * 2 > upp - used) return false;
    used += need[i] * 2;
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, n) scanf("%d", k + i);
  FOR(i, 1, m) scanf("%d%d", &off[i]._1, &off[i]._2);
  sort(off + 1, off + m + 1);
  int lo = 1, hi = 4e5 + 10;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  printf("%d", lo);
}