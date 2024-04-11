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
  string s;
  cin >> n >> s;
  n += n;
  vector<int> pre(n + 1);
  REP(i, n) pre[i + 1] = pre[i] + (s[i] == '(' ? 1 : -1);
  if (*min_element(all(pre)) >= 0) {
    cout << "0\n";
    return;
  }
  int l = 0, r = n;
  REP(i, n + 1) {
    if (pre[i] < 0) break;
    if (pre[i] > pre[l]) l = i;
  }
  ROF(i, n, 0) {
    if (pre[i] < 0) break;
    if (pre[i] > pre[r]) r = i;
  }
  if (*max_element(pre.begin() + l, pre.begin() + r) <= pre[l] + pre[r]) {
    cout << "1\n";
    cout << l + 1 << ' ' << r << '\n';
    return;
  }
  int mi = max_element(pre.begin(), pre.begin() + n) - pre.begin();
  cout << "2\n";
  cout << "1 " << mi << '\n';
  cout << mi + 1 << ' ' << n << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}