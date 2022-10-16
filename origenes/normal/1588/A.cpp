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
  int n; cin >> n;
  vector<int> a(n), b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];
  vector<int> ca(201), cb(201);
  REP(i, n) ca[a[i] + 100]++;
  REP(i, n) cb[b[i] + 100]++;
  int need = 0;
  ROF(i, 200, 0) {
    if (cb[i] < ca[i]) {
      cout << "NO\n";
      return;
    }
    cb[i] -= ca[i];
    if (cb[i] > 0 && i > 0) {
      if (cb[i] > ca[i - 1]) {
        cout << "NO\n";
        return;
      }
      ca[i - 1] -= cb[i];
      cb[i] = 0;
    }
    if (cb[i] > 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}