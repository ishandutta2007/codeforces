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

const int maxn = 112;

int n, c[maxn][maxn];
vector<int> dups[maxn];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  REP(i, n) REP(j, n) {
    int x; cin >> x;
    x--;
    if (++c[i][x] > 1) dups[i].eb(x);
  }
  vector<vector<int>> ans;
  while (true) {
    vector<int> ops(n);
    int s = -1;
    REP(i, n) if (!dups[i].empty()) {
      s = i;
      break;
    }
    if (s == -1) break;
    int last = -1;
    FOR(i, s, s + n - 1) {
      int idx = i % n;
      if (!dups[idx].empty()) {
        last = dups[idx].back();
        dups[idx].pop_back();
      }
      ops[idx] = last;
    }
    ans.eb(ops);
    REP(i, n) {
      int right = (i + 1) % n;
      c[i][ops[i]]--;
      c[right][ops[i]]++;
    }
    REP(i, n) {
      int right = (i + 1) % n;
      if (c[right][ops[i]] > 1) dups[right].eb(ops[i]);
    }
  }
  FOR(i, 1, n - 1) {
    vector<int> ops;
    REP(j, n) ops.eb((j - i + n) % n);
    REP(j, i) ans.eb(ops);
  }
  cout << size(ans) << '\n';
  for (auto ops : ans) {
    for (auto x : ops) cout << x + 1 << ' ';
    cout << '\n';
  }
}