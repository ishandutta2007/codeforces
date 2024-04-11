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

int fac2(int x) {
  int ret = 1;
  while (x % 2 == 0) {
    x /= 2;
    ret *= 2;
  }
  return ret;
}

int h[32][32], v[32][32], f[32][32];

int main() {
  int n, k;
  cin >> n >> k;
  REP(i, 32) FOR(j, 1, 31) h[i][j - 1] = sqr(fac2(j));
  FOR(i, 1, 31) REP(j, 32) v[i - 1][j] = 2 * sqr(fac2(i));
  REP(i, n) {
    REP(j, n - 1) cout << h[i][j] << ' ';
    cout << endl;
  }
  REP(i, n - 1) {
    REP(j, n) cout << v[i][j] << ' ';
    cout << endl;
  }
  FOR(j, 1, n - 1) f[0][j] = f[0][j - 1] ^ h[0][j - 1];
  FOR(i, 1, n - 1) REP(j, n) f[i][j] = f[i - 1][j] ^ v[i - 1][j];
  map<int, pii> pos;
  REP(i, n) REP(j, n) pos[f[i][j]] = {i + 1, j + 1};
  int pre = 0;
  while (k--) {
    int x; cin >> x;
    auto [i, j] = pos[pre ^= x];
    cout << i << ' ' << j << endl;
  }
}