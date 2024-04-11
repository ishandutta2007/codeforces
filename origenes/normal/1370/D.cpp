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

int n, k, a[maxn];

bool check(int up) {
  vector<int> sel;
  FOR(i, 1, n) {
    if (a[i] <= up) sel.eb(i);
    else if (sel.size() % 2 == 1) sel.eb(i);
    if (sel.size() == k) return true;
  }
  sel.clear();
  FOR(i, 1, n) {
    if (a[i] <= up) sel.eb(i);
    else if (sel.size() % 2 == 0) sel.eb(i);
    if (sel.size() == k) return true;
  }
  return false;
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%d", a + i);
  int lo = 1, hi = 1e9;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (check(mi)) hi = mi;
    else lo = mi + 1;
  }
  printf("%d", lo);
}