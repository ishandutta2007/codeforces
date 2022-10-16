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
  int n;
  cin >> n;
  int a[4] = {};
  REP(i, 4) cin >> a[i];
  REP(mask, 1 << 4) {
    REP(i, 4) if (mask & (1 << i)) {
      a[i]--;
      a[(i + 1) % 4]--;
    }
    bool bad = false;
    REP(i, 4) if (a[i] < 0 || a[i] > n - 2) {
      REP(j, 4) if (mask & (1 << j)) {
        a[j]++;
        a[(j + 1) % 4]++;
      }
      bad = true;
      break;
    }
    if (!bad) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}