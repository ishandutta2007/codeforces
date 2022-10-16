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

ll f[50];

void solve() {
  int n; cin >> n;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  if (n > 49) {
    cout << "NO\n";
    return;
  }
  ll s = accumulate(all(a), 0LL), have = 0;
  int reach = -1;
  REP(i, 50) {
    have += f[i];
    if (s == have) {
      reach = i;
      break;
    }
  }
  if (reach == -1) {
    cout << "NO\n";
    return;
  }
  int last = -1;
  ROF(i, reach, 0) {
    int mx = -1, best = -1;
    REP(j, n) if (a[j] > mx && j != last) {
      mx = a[j];
      best = j;
    }
    if (mx < f[i]) {
      cout << "NO\n";
      return;
    }
    a[best] -= f[i];
    last = best;
  }
  cout << "YES\n";
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  f[0] = f[1] = 1;
  FOR(i, 2, 49) f[i] = f[i - 1] + f[i - 2];
  int T; cin >> T;
  while (T--) solve();
}