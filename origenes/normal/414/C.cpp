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

const int maxn = 1123456;

int n, a[maxn], m;
ll ans[25][2];

void build(int dep, int l, int r) {
  if (dep != n) {
    int mi = l + r >> 1;
    build(dep + 1, l, mi);
    build(dep + 1, mi + 1, r);
    int j = mi + 1;
    FOR(i, l, mi) {
      while (j <= r && a[j] <= a[i]) j++;
      ans[n - dep][0] += r - j + 1;
    }
    j = mi + 1;
    FOR(i, l, mi) {
      while (j <= r && a[j] < a[i]) j++;
      ans[n - dep][1] += j - mi - 1;
    }
    sort(a + l, a + r + 1);
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, 1 << n) cin >> a[i];
  build(0, 0, (1 << n) - 1);
  cin >> m;
  while (m--) {
    int q; cin >> q;
    FOR(i, 1, q) swap(ans[i][0], ans[i][1]);
    ll res = 0;
    FOR(i, 1, n) res += ans[i][1];
    cout << res << '\n';
  }
}