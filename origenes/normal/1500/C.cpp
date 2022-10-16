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

const int maxn = 1512;

int n, m;
vector<int> a[maxn], b[maxn];
int pos[2][maxn], cnt[maxn];
bool vr[maxn], vc[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  REP(i, n) {
    a[i].resize(m);
    REP(j, m) cin >> a[i][j];
  }
  REP(i, n) {
    b[i].resize(m);
    REP(j, m) cin >> b[i][j];
  }
  REP(i, 2) iota(pos[i], pos[i] + n, 0);
  stable_sort(pos[0], pos[0] + n, [](int x, int y) { return a[x] < a[y]; });
  stable_sort(pos[1], pos[1] + n, [](int x, int y) { return b[x] < b[y]; });
  REP(i, n) if (a[pos[0][i]] != b[pos[1][i]]) {
    cout << -1;
    return 0;
  }
  REP(i, n) a[i].eb(i);
  REP(i, n) b[pos[1][i]].eb(pos[0][i]);
  FOR(i, 1, n - 1) REP(j, m + 1) if (b[i][j] < b[i - 1][j]) cnt[j]++;
  vector<int> ans;
  bool f = true;
  while (cnt[m] > 0 && f) {
    f = false;
    REP(i, m) if (!cnt[i] && !vc[i]) {
      f = vc[i] = true;
      ans.eb(i);
      FOR(j, 1, n - 1) if (!vr[j] && b[j][i] > b[j - 1][i]) {
        vr[j] = true;
        REP(k, m + 1) if (b[j][k] < b[j - 1][k]) cnt[k]--;
      }
      break;
    }
  }
  if (cnt[m] > 0) {
    cout << -1;
    return 0;
  }
  reverse(all(ans));
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x + 1 << ' ';
}