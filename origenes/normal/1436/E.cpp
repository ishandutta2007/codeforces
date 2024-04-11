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

int n, a[maxn], last[maxn], nex[maxn];
bool vis[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) if (a[i] > 1) vis[1] = true;
  if (!vis[1]) {
    puts("1");
    return 0;
  }
  fill(last + 1, last + n + 2, n + 1);
  ROF(i, n, 1) {
    nex[i] = last[a[i]];
    last[a[i]] = i;
  }
  int mx = 0;
  multiset<pii> peaks;
  FOR(i, 1, n + 1) if (last[i] > mx) {
    vis[i] = true;
    peaks.emplace(i, last[i]);
    chkmax(mx, last[i]);
  }
  FOR(i, 2, n) {
    auto it = peaks.lower_bound(mp(a[i - 1], 0));
    if (it == peaks.begin() || prev(it)->_2 < nex[i - 1]) {
      vis[a[i - 1]] = true;
      while (it != peaks.end() && it->_2 <= nex[i - 1]) {
        it++;
        peaks.erase(prev(it));
      }
      peaks.emplace(a[i - 1], nex[i - 1]);
    }
  }
  FOR(i, 1, n + 2) if (!vis[i]) {
    printf("%d", i);
    return 0;
  }
}