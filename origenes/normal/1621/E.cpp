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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1);
  FOR(i, 1, n) cin >> a[i];
  sort(a.begin() + 1, a.end(), greater<>());
  vector<vector<int>> b(m + 1);
  vector<ll> sum(m + 1);
  vector<pii> avg(m + 1);
  vector<int> idx(m + 1), cp(m + 1), c(m + 1), cn(m + 1);
  FOR(i, 1, m) {
    int k; cin >> k;
    b[i].resize(k);
    REP(j, k) {
      cin >> b[i][j];
      sum[i] += b[i][j];
    }
    avg[i] = {(sum[i] + k - 1) / k, i};
  }
  sort(avg.begin() + 1, avg.end(), greater<>());
  FOR(i, 1, m) idx[avg[i]._2] = i;
  FOR(i, 2, m) cp[i] = cp[i - 1] + (a[i] >= avg[i - 1]._1);
  FOR(i, 1, m) c[i] = c[i - 1] + (a[i] >= avg[i]._1);
  FOR(i, 1, m - 1) cn[i] = cn[i - 1] + (a[i] >= avg[i + 1]._1);
  string ans;
  FOR(i, 1, m) {
    int k = b[i].size(), id = idx[i];
    for (auto now : b[i]) {
      int navg = (sum[i] - now + k - 2) / (k - 1);
      int lo = 1, hi = m;
      while (lo <= hi) {
        int mi = lo + hi >> 1;
        if (avg[mi]._1 >= navg) lo = mi + 1;
        else hi = mi - 1;
      }
      char res = '0';
      if (lo <= id) {
        if (c[lo - 1] >= lo - 1 && a[lo] >= navg && cp[id] - cp[lo] >= id - lo && c[m] - c[id] >= m - id)
          res = '1';
      } else {
        if (c[id - 1] >= id - 1 && cn[lo - 2] - cn[id - 1] >= lo - id - 1 && a[lo - 1] >= navg && c[m] - c[lo - 1] >= m - lo + 1)
          res = '1';
      }
      ans += res;
    }
  }
  cout << ans << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}