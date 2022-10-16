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

bool ask(vector<int> l, vector<int> r) {
  cout << "? " << l.size() << ' ' << r.size() << endl;
  for (auto x : l) cout << x << ' ';
  cout << endl;
  for (auto x : r) cout << x << ' ';
  cout << endl;
  int ret;
  cin >> ret;
  return ret != 0;
}

void answer(vector<int> ans) {
  cout << "! " << ans.size();
  for (auto x : ans) cout << ' ' << x;
  cout << endl;
}

void solve() {
  int n;
  cin >> n;
  vector<int> l = {1};
  FOR(r, 2, n) {
    if (ask(l, {r})) break;
    l.eb(r);
  }
  int lo = 0, hi = int(l.size()) - 1;
  int r = l.back() + 1;
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (ask(vector<int>(l.begin(), l.begin() + mi + 1), {r})) hi = mi;
    else lo = mi + 1;
  }
  vector<int> ans;
  for (auto x : l) if (x != l[lo]) ans.eb(x);
  FOR(i, r + 1, n) if (!ask({r}, {i})) ans.eb(i);
  answer(ans);
}

int main() {
  int T; cin >> T;
  while (T--) solve();
}