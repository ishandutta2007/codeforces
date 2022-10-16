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
  vector<string> s(n);
  REP(i, n) cin >> s[i];
  set<string> s22, s32, s33;
  REP(i, n) {
    auto t = s[i];
    reverse(all(t));
    if (s[i] == t) {
      cout << "YES\n";
      return;
    }
    if (s[i].length() == 2) {
      if (s22.count(t) || s32.count(t)) {
        cout << "YES\n";
        return;
      }
      s22.emplace(s[i]);
    } else {
      string u = t.substr(0, 2);
      if (s33.count(t) || s22.count(u)) {
        cout << "YES\n";
        return;
      }
      s33.emplace(s[i]);
      s32.emplace(s[i].substr(0, 2));
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