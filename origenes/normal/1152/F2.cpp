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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int MOD = 1e9 + 7;
const int maxn = 255;

int n, k, m, bit[maxn], ALL, ans;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

vector<vector<int>> mul(const vector<vector<int>> &a, const vector<vector<int>> &b) {
  int sz = a.size();
  vector<vector<int>> ret(sz, vector<int>(sz));
  REP(i, sz) REP(j, sz) REP(k, sz) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
  return ret;
}

vector<vector<int>> pow_mod(vector<vector<int>> A, int sz, int pw) {
  vector<vector<int>> ret(sz, vector<int>(sz));
  REP(i, sz) ret[i][i] = 1;
  while (pw) {
    if (pw & 1) ret = mul(ret, A);
    A = mul(A, A);
    pw >>= 1;
  }
  return ret;
}

int main() {
  scanf("%d%d%d", &n, &k, &m);
  ALL = (1 << m) - 1;
  FOR(mask, 1, ALL) bit[mask] = bit[mask - (mask & -mask)] + 1;
  vector<vector<int>> A = vector<vector<int>>((k + 1) * (ALL + 1), vector<int>((k + 1) * (ALL + 1)));
  REP(mask, ALL + 1) REP(i, k + 1) {
    A[i * (ALL + 1) + mask][i * (ALL + 1) + (ALL & (mask << 1))]++;
    if (i != k) A[i * (ALL + 1) + mask][(i + 1) * (ALL + 1) + (ALL & (mask << 1)) + 1] += bit[mask] + 1;
  }
  A = pow_mod(A, (k + 1) * (ALL + 1), n);
  REP(mask, ALL + 1) ans = add(ans, A[0][k * (ALL + 1) + mask]);
  printf("%d", ans);
}