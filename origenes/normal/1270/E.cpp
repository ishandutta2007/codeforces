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

int x[maxn], y[maxn];

int main() {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d%d", x + i, y + i);
  bool found = false;
  FOR(i, 2, n) {
    x[i] -= x[1], y[i] -= y[1];
    if (x[i] & 1) found = true;
    if (y[i] & 1) found = true;
  }
  x[1] = 0, y[1] = 0;
  while (!found) FOR(i, 1, n) {
    x[i] /= 2, y[i] /= 2;
    if (x[i] & 1) found = true;
    if (y[i] & 1) found = true;
  }
  vector<int> ans;
  FOR(i, 1, n) if ((x[i] & 1) == (y[i] & 1)) ans.eb(i);
  if (ans.size() == n || ans.empty()) {
    ans.clear();
    FOR(i, 1, n) if (x[i] & 1) ans.eb(i);
  }
  printf("%d\n", int(ans.size()));
  for (auto i : ans) printf("%d ", i);
}