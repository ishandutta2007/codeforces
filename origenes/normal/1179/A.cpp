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

int n, q, mx;
int a[maxn];

int main() {
  scanf("%d%d",&n, &q);
  deque<int> que;
  FOR(i, 1, n) {
    scanf("%d", a + i);
    chkmax(mx, a[i]);
    que.eb(a[i]);
  }
  vector<pii> ans;
  while (que.front() != mx) {
    auto x = que.front(); que.pop_front();
    auto y = que.front(); que.pop_front();
    ans.eb(x, y);
    if (y > x) swap(x, y);
    que.emplace_front(x);
    que.eb(y);
  }
  while (q--) {
    ll m;
    scanf("%lld", &m);
    if (m <= ans.size()) printf("%d %d\n", ans[m - 1]._1, ans[m - 1]._2);
    else {
      m -= ans.size();
      m = m % (n - 1);
      if (!m) m = n - 1;
      printf("%d %d\n", mx, que[m]);
    }
  }
}