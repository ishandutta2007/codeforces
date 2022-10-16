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

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, m, p;
  cin >> n >> m >> p;
  vector<string> mat(n);
  REP(i, n) cin >> mat[i];
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<> distrib(0, n - 1);
  int ans = 0;
  string best = string(m, '0');
  REP(_, 50) {
    int id = distrib(rng);
    vector<int> pos;
    REP(j, m) if (mat[id][j] == '1') pos.eb(j);
    int tot = pos.size();
    vector<int> f(1 << tot);
    REP(i, n) {
      int mask = 0;
      REP(j, tot) if (mat[i][pos[j]] == '1') mask |= 1 << j;
      f[((1 << tot) - 1) ^ mask]++;
    }
    REP(i, tot) REP(mask, 1 << tot) if (mask & (1 << i)) f[mask] += f[mask ^ (1 << i)];
    REP(mask, 1 << tot) if (f[mask] >= (n + 1) / 2 && __builtin_popcount(((1 << tot) - 1) ^ mask) > ans) {
      ans = __builtin_popcount(((1 << tot) - 1) ^ mask);
      best = string(m, '0');
      REP(j, tot) if ((mask & (1 << j)) == 0) best[pos[j]] = '1';
    }
  }
  cout << best;
}