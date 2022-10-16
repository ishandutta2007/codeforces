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

inline void update(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

struct Matrix {
  int n;
  vector<vector<int>> mat;

  explicit Matrix (int n) : n(n) {
    mat = vector<vector<int>>(n, vector<int>(n));
  }

  Matrix operator * (const Matrix &rhs) {
    Matrix ret(n);
    REP(i, n) REP(j, n) REP(k, n) update(ret.mat[i][j], mul(mat[i][k], rhs.mat[k][j]));
    return ret;
  }
};

Matrix pow_mod(Matrix a, ll k) {
  Matrix ret(a.n);
  REP(i, a.n) ret.mat[i][i] = 1;
  while (k) {
    if (k & 1) ret = ret * a;
    a = a * a;
    k >>= 1;
  }
  return ret;
}

int n;
ll k;

int main() {
  scanf("%d%lld", &n, &k);
  vector<int> vec(20);
  vec[0] = 1;
  REP(i, n) {
    ll a, b;
    int c;
    scanf("%lld%lld%d", &a, &b, &c);
    chkmin(b, k);
    ROF(j, 15, c + 1) vec[j] = 0;
    Matrix now(c + 1);
    REP(ii, c + 1) FOR(jj, -1, 1) if (ii + jj >= 0 && ii + jj <= c) now.mat[ii][ii + jj] = 1;
    now = pow_mod(now, b - a);
    vector<int> vv(20);
    REP(ii, c + 1) REP(jj, c + 1) update(vv[ii], mul(vec[jj], now.mat[ii][jj]));
    swap(vv, vec);
  }
  printf("%d", vec[0]);
}