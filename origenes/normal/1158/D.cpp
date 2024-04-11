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

const int maxn = 2123;

int n, x[maxn], y[maxn];
bool vis[maxn];
char s[maxn];

inline int cross(int i, int j, int k) {
  ll ans = (x[j] - x[i]) * ll(y[k] - y[i]) - ll(y[j] - y[i]) * (x[k] - x[i]);
  if (!ans) return 0;
  return ans > 0 ? 1 : -1;
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d%d", x + i, y + i);
  scanf("%s", s + 1);
  int idx = 1;
  FOR(i, 2, n) if (y[i] < y[idx] || (y[i] == y[idx] && x[i] < x[idx])) idx = i;
  vector<int> ans;
  FOR(i, 1, n - 2) {
    vis[idx] = true;
    ans.eb(idx);
    int now = -1;
    if (s[i] == 'L') {
      FOR(j, 1, n) if (!vis[j] && (now < 0 || cross(idx, now, j) <= 0)) now = j;
    } else {
      FOR(j, 1, n) if (!vis[j] && (now < 0 || cross(idx, now, j) >= 0)) now = j;
    }
    idx = now;
  }
  ans.eb(idx);
  vis[idx] = true;
  FOR(i, 1, n) if (!vis[i]) {
    ans.eb(i);
    break;
  }
  for (auto it : ans) printf("%d ", it);
}