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

vector<int> G[10];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  REP(i, n) {
    int c; cin >> c;
    G[i].resize(c);
    REP(j, c) cin >> G[i][j];
  }
  int m; cin >> m;
  vector<vector<int>> bans(m, vector<int>(n));
  REP(i, m) REP(j, n) cin >> bans[i][j];
  sort(all(bans));
  ll ans = 0, cur = 0;
  vector<int> best, now(n);
  REP(i, n) {
    now[i] = G[i].size();
    cur += G[i].back();
  }
  auto it = lower_bound(all(bans), now);
  if (it == bans.end() || *it != now) {
    ans = cur;
    best = now;
  }
  for (auto now : bans) {
    cur = 0;
    REP(i, n) cur += G[i][now[i] - 1];
    REP(i, n) if (now[i] > 1) {
      cur = cur - G[i][now[i] - 1] + G[i][now[i] - 2];
      now[i]--;
      it = lower_bound(all(bans), now);
      if ((it == bans.end() || *it != now) && cur > ans) {
        ans = cur;
        best = now;
      }
      now[i]++;
      cur = cur + G[i][now[i] - 1] - G[i][now[i] - 2];
    }
  }
  for (auto x : best) cout << x << ' ';
}