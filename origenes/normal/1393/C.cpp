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

int a[maxn], n, cnt[maxn];
vector<int> in[maxn];

bool check(int allow) {
  FOR(i, 1, n) cnt[i] = 0;
  FOR(i, 1, n) cnt[a[i]]++;
  FOR(i, 1, n) in[i].clear();
  priority_queue<pii> q;
  FOR(i, 1, n) if (cnt[i]) q.emplace(cnt[i], i);
  FOR(i, 1, n) {
    for (auto x : in[i]) q.emplace(cnt[x], x);
    if (q.empty()) return false;
    auto [c, x] = q.top(); q.pop();
    if (--cnt[x] && i + allow <= n) in[i + allow].eb(x);
  }
  return true;
}

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  int lo = 1, hi = n - 1;
  while (lo < hi) {
    int mi = lo + hi + 1 >> 1;
    if (check(mi)) lo = mi;
    else hi = mi - 1;
  }
  printf("%d\n", lo - 1);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}