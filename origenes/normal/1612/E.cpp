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

const int maxn = 212345;

int n;
int cnt[maxn][21];

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  while (n--) {
    int m, k;
    cin >> m >> k;
    cnt[m][k]++;
  }
  ll tot = 0;
  vector<int> ans;
  vector<pii> seq;
  FOR(i, 1, 20) {
    seq.clear();
    FOR(j, 1, 2e5) {
      int c = 0;
      FOR(k, 1, 20) c += cnt[j][k] * min(k, i);
      if (c != 0) seq.eb(c, j);
    }
    if (seq.size() >= i) {
      sort(all(seq), greater<>());
      ll now = 0;
      REP(j, i) now += seq[j]._1;
      if (tot == 0 || tot * i < now * ans.size()) {
        tot = now;
        ans.clear();
        REP(j, i) ans.eb(seq[j]._2);
      }
    }
  }
  if (seq.size() > 20) {
    int best = -1;
    ll now = 0;
    REP(j, 20) now += seq[j]._1;
    FOR(j, 20, seq.size()) {
      now += seq[j]._1;
      if (best == -1 && tot * (j + 1) < now * ans.size()) {
        best = j + 1;
        tot = now;
      }
      if (best != -1 && tot * (j + 1) < now * best) {
        best = j + 1;
        tot = now;
      }
    }
    if (best != -1) {
      ans.clear();
      REP(j, best) ans.eb(seq[j]._2);
    }
  }
  cout << ans.size() << '\n';
  for (auto x : ans) cout << x << ' ';
}