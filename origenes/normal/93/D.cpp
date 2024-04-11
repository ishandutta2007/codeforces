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
const int i2 = 5e8 + 4;

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

vector<vector<int>> mul(const vector<vector<int>> &a, const vector<vector<int>> &b) {
  vector<vector<int>> ret(9, vector<int>(9));
  REP(i, 9) REP(j, 9) REP(k, 9) ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
  return ret;
}

vector<vector<int>> pow_mod(vector<vector<int>> a, int k) {
  vector<vector<int>> ret(9, vector<int>(9));
  REP(i, 9) ret[i][i] = 1;
  while (k) {
    if (k & 1) ret = mul(ret, a);
    a = mul(a, a);
    k >>= 1;
  }
  return ret;
}

int solve(int x) {
  vector<vector<int>> st(9, vector<int>(9));
  st[0][2] = st[0][3] = 1; st[0][5] = MOD - 1;
  st[1][2] = st[1][3] = 1; st[1][4] = MOD - 1;
  st[2][0] = st[2][1] = st[3][0] = st[3][1] = 1;
  st[4][0] = st[5][1] = st[6][2] = st[7][3] = 1;
  st[8][0] = st[8][1] = st[8][2] = st[8][3] = st[8][8] = 1;
  vector<vector<int>> a(st);
  int ret = 0;
  a = pow_mod(a, x);
  REP(i, 4) ret = add(ret, a[8][i]);
  a = st;
  a = pow_mod(a, x + 1 >> 1);
  REP(i, 4) ret = add(ret, a[8][i]);
  return mul(ret, i2);
}

int main() {
  int l, r;
  scanf("%d%d", &l, &r);
  printf("%d", add(solve(r), MOD - solve(l - 1)));
}