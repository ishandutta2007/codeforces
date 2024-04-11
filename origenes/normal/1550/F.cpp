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

int a[maxn], f[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, q, s, d;
  cin >> n >> q >> s >> d;
  FOR(i, 1, n) cin >> a[i];
  set<int> rem, anchors;
  reset(f, -1);
  FOR(i, 1, n) rem.emplace(i);
  set<pii> Q; Q.emplace(0, s);
  while (!Q.empty()) {
    auto [dis, u] = *Q.begin(); Q.erase(Q.begin());
    rem.erase(u);
    if (f[u] >= 0) continue;
    f[u] = dis;
    for (int p = a[u] - d; p <= a[u] + d; p += 2 * d) {
      anchors.emplace(p);
      auto it = rem.lower_bound(lower_bound(a + 1, a + n + 1, p) - a);
      if (it != rem.end()) Q.emplace(max(dis, a[*it] - p), *it);
      if (it != rem.begin()) {
        it--;
        Q.emplace(max(dis, p - a[*it]), *it);
      }
    }
    auto g = [&](int x) {
      auto it = anchors.lower_bound(a[x]);
      int ret = 1e9;
      if (it != anchors.end()) chkmin(ret, *it - a[x]);
      if (it != anchors.begin()) {
        it--;
        chkmin(ret, a[x] - *it);
      }
      return ret;
    };
    auto it = rem.lower_bound(u);
    if (it != rem.end()) Q.emplace(max(dis, g(*it)), *it);
    if (it != rem.begin()) {
      it--;
      Q.emplace(max(dis, g(*it)), *it);
    }
  }
  while (q--) {
    int i, k;
    cin >> i >> k;
    if (k >= f[i]) cout << "Yes\n";
    else cout << "No\n";
  }
}