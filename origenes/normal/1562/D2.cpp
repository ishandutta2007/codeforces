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
  int n, q;
  cin >> n >> q;
  string s; cin >> s;
  vector<int> pre(n + 1);
  map<int, vector<int>> ids;
  FOR(i, 1, n) {
    pre[i] = s[i - 1] == '+' ? 1 : -1;
    if (i % 2 == 0) pre[i] = -pre[i];
    pre[i] = pre[i - 1] + pre[i];
    ids[pre[i - 1] + pre[i]].eb(i);
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (pre[r] - pre[l - 1] == 0) {
      cout << "0\n";
      continue;
    }
    vector<int> ans;
    if ((r - l) % 2 == 1) {
      ans.eb(r);
      r--;
    }
    int x = pre[l - 1] + pre[r];
    assert(ids.count(x));
    auto it = lower_bound(all(ids[x]), l);
    assert(it != ids[x].end() && *it <= r);
    ans.eb(*it);
    reverse(all(ans));
    cout << ans.size() << '\n';
    for (auto u : ans) cout << u << ' ';
    cout << '\n';
  }
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}