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

int n, a[maxn];

void solve() {
  scanf("%d", &n);
  REP(i, n) scanf("%d", a + i);
  auto mex = [&]() -> int {
    vector<char> vis(n + 1);
    REP(i, n) vis[a[i]] = true;
    REP(i, n + 1) if (!vis[i]) return i;
  };
  auto check = [&]() -> bool {
    FOR(i, 1, n - 1) if (a[i] < a[i - 1]) return false;
    return true;
  };
  vector<int> ans;
  while (!check()) {
    int i = mex();
    if (i == n) {
      REP(j, n) if (a[j] != j) {
        a[j] = n;
        ans.eb(j + 1);
        break;
      }
    } else {
      a[i] = i;
      ans.eb(i + 1);
    }
  }
  printf("%d\n", int(ans.size()));
  for (auto it : ans) printf("%d ", it);
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}