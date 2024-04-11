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

const int maxn = 1123;

int ask(int l, int r) {
  cout << "? " << r - l + 1;
  FOR(i, l, r) cout << " " << i;
  cout << endl;
  int ret; cin >> ret;
  return ret;
}

int n, k, ans[maxn];
vector<int> G[maxn];

int ask(const vector<int> &v) {
  vector<char> mark(n + 1);
  int cnt = n;
  for (auto x : v) mark[x] = true, cnt--;
  cout << "? " << cnt;
  FOR(i, 1, n) if (!mark[i]) cout << ' ' << i;
  cout << endl;
  int ret; cin >> ret;
  return ret;
}


void answer() {
  cout << '!';
  FOR(i, 1, k) cout << ' ' << ans[i];
  cout << endl;
  string s;
  cin >> s;
  assert(s == "Correct");
}

void solve() {
  cin >> n >> k;
  FOR(i, 1, k) G[i].clear();
  FOR(i, 1, k) {
    int c; cin >> c;
    G[i].resize(c);
    for (auto &x : G[i]) cin >> x;
  }
  int lo = 1, hi = n;
  int mx = ask(1, n);
  while (lo < hi) {
    int mi = lo + hi >> 1;
    if (ask(lo, mi) != mx) lo = mi + 1;
    else hi = mi;
  }
  FOR(i, 1, k) {
    bool f = false;
    for (auto x : G[i]) if (x == lo) {
      ans[i] = ask(G[i]);
      f = true;
    }
    if (!f) ans[i] = mx;
  }
  answer();
}

int main() {
  int T; cin >> T;
  while (T--) solve();
}