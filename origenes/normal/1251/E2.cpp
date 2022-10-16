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

int n;
int m[maxn], p[maxn];
vector<int> G[maxn];

void solve() {
  scanf("%d", &n);
  vector<int> interested;
  interested.reserve(n);
  FOR(i, 1, n) {
    scanf("%d%d", m + i, p + i);
    G[m[i]].clear();
    interested.eb(m[i]);
  }
  FOR(i, 1, n) G[m[i]].eb(p[i]);
  sort(all(interested));
  uni(interested);
  map<int, int> cnt;
  int past = 0, sel = 0;
  ll ans = 0;
  ROF(_i, int(interested.size()) - 1, 0) {
    int i = interested[_i], have = n - past - int(G[i].size()), need = i - have - sel;
    for (auto x : G[i]) cnt[x]++, past++;
    while (need > 0) {
      int np = cnt.begin()->_1;
      ans += np;
      sel++;
      if (!--cnt[np]) cnt.erase(np);
      need--;
    }
  }
  printf("%lld\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}