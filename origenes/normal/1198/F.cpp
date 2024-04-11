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

vector<int> fac(int x) {
  if (x == 1) return {};
  vector<int> ret;
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      ret.eb(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x != 1) ret.eb(x);
  return ret;
}

const int maxn = 112345;
const double eps = 1e-6;

int n, a[maxn], ans[maxn];

int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  auto v1 = fac(a[1]);
  int k1 = v1.size();
  double e = k1 / double(n - 1), err = 1;
  set<int> checked;
  bool found = false;
  while (err >= eps && checked.size() < n - 1) {
    err *= e;
    int u = -1;
    do {
      u = uniform_int_distribution<int>(2, n)(rng);
    } while (checked.count(u));
    checked.emplace(u);
    auto v2 = fac(a[u]);
    int k2 = v2.size();
    vector<vector<char>> good(n + 1, vector<char>(20));
    FOR(i, 2, n) REP(j, k1) good[i][j] = a[i] % v1[j] != 0;
    FOR(i, 2, n) REP(j, k2) good[i][j + k1] = a[i] % v2[j] != 0;
    vector<pair<int, pii>> candidates;
    vector<int> need(20, k1 + k2);
    FOR(i, 2, n) if (i != u) {
        bool sel = false;
        REP(j, k1 + k2) if (need[j] && good[i][j]) {
            sel = true;
            need[j]--;
            break;
          }
        if (sel) {
          int mask1 = 0, mask2 = 0;
          REP(j, k1) mask1 |= (good[i][j] << j);
          REP(j, k2) mask2 |= (good[i][j + k1] << j);
          candidates.eb(i, mp(mask1, mask2));
        }
      }
    vector<vector<vector<pii>>> f;
    f.resize(candidates.size() + 1);
    for (auto &g : f) {
      g.resize(1 << k1);
      for (auto &h : g) h = vector<pii>(1 << k2, mp(-1, -1));
    }
    f[0][0][0] = {0, 0};
    REP(i, int(candidates.size())) REP(mask1, 1 << k1) REP(mask2, 1 << k2) {
          if (f[i][mask1][mask2]._1 == -1) continue;
          int m1 = candidates[i]._2._1, m2 = candidates[i]._2._2;
          int nmask1 = mask1 | m1, nmask2 = mask2 | m2;
          if (f[i + 1][nmask1][mask2]._1 == -1) f[i + 1][nmask1][mask2] = {mask1, mask2};
          if (f[i + 1][mask1][nmask2]._2 == -1) f[i + 1][mask1][nmask2] = {mask1, mask2};
        }
    if (f[candidates.size()][(1 << k1) - 1][(1 << k2) - 1]._1 == -1) continue;
    int mask1 = (1 << k1) - 1, mask2 = (1 << k2) - 1;
    ans[1] = 1;
    ans[u] = 2;
    ROF(i, candidates.size(), 1) {
      if (mask1 == f[i][mask1][mask2]._1) {
        ans[candidates[i - 1]._1] = 2;
        mask2 = f[i][mask1][mask2]._2;
      } else {
        ans[candidates[i - 1]._1] = 1;
        mask1 = f[i][mask1][mask2]._1;
      }
    }
    FOR(i, 2, n) if (!ans[i]) ans[i] = 1;
    found = true;
    break;
  }
  if (found) {
    puts("YES");
    FOR(i, 1, n) printf("%d ", ans[i]);
  } else puts("NO");
}