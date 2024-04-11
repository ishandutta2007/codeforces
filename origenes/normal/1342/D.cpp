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

const int maxn = 212345;

int n, k;
int cnt[maxn], c[maxn], tmp[maxn];
vector<int> a[maxn];

bool check(int LIM) {
  REP(i, LIM) a[i].clear();
  memcpy(tmp, cnt, sizeof(cnt));
  int j = 0;
  ROF(i, k, 1) {
    while (tmp[i]--) {
      if (a[j].size() < c[i]) {
        a[j].eb(i);
        continue;
      }
      int pj = j; j = (j + 1) % LIM;
      while (j != pj && a[j].size() == c[i]) j = (j + 1) % LIM;
      if (j == pj) return false;
      a[j].eb(i);
    }
  }
  return true;
}

int main() {
  scanf("%d%d", &n, &k);
  int m;
  FOR(i, 1, n) {
    scanf("%d", &m);
    cnt[m]++;
  }
  FOR(i, 1, k) scanf("%d", c + i);
  int lo = 1, hi = n;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  check(lo);
  printf("%d\n", lo);
  REP(i, lo) {
    printf("%d", int(a[i].size()));
    for (auto x : a[i]) printf(" %d", x);
    putchar('\n');
  }
}