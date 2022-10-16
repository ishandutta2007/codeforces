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

const int e5 = 1e5;

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m;
  cin >> n >> m;
  vector<char> vis(m + 1);
  vector<int> ans(m + 1, -1);
  vis[0] = 1;
  vector<int> have = {0};
  FOR(i, 1, n) {
    int t, y;
    ll x;
    cin >> t >> x >> y;
    vector<int> nex;
    if (t == 1) {
      ll inc = (x + e5 - 1) / e5;
      for (auto st : have) {
        FOR(j, 1, y) {
          if (st + j * inc > m || vis[st + j * inc]) break;
          ans[st + j * inc] = i;
          vis[st + j * inc] = 1;
          nex.eb(st + j * inc);
        }
      }
    } else {
      for (auto st : have) {
        FOR(j, 1, y) {
          ll now = (st * x + e5 - 1) / e5;
          if (now > m || vis[now]) break;
          ans[now] = i;
          vis[now] = 1;
          nex.eb(now);
          st = now;
        }
      }
    }
    for (auto cur : nex) have.eb(cur);
    sort(all(have), greater<>());
  }
  FOR(i, 1, m) cout << ans[i] << ' ';
}