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

const int MOD = 1e6 + 3;
const int maxn = 12;

typedef int Matrix[maxn][maxn];

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int inv(int a) {
  int ret = 1, pw = MOD - 2;
  while (pw) {
    if (pw & 1) ret = mul(ret, a);
    a = mul(a, a);
    pw >>= 1;
  }
  return ret;
}

void gauss(Matrix A, int n) {
  REP(i, n) {
    int r = i;
    FOR(j, i + 1, n - 1) if (A[j][i] > A[r][i]) r = j;
    if (r != i) FOR(j, i, n) swap(A[i][j], A[r][j]);
    FOR(k, i + 1, n - 1) ROF(j, n, i)
      A[k][j] = add(A[k][j], MOD - mul(A[k][i], mul(inv(A[i][i]), A[i][j])));
  }
  ROF(i, n - 1, 0) {
    FOR(j, i + 1, n - 1) A[i][n] = add(A[i][n], MOD - mul(A[i][j], A[j][n]));
    A[i][n] = mul(A[i][n], inv(A[i][i]));
  }
}

Matrix A;
int coeff[maxn], p[maxn];

int ask(int x) {
  cout << "? " << x << endl;
  int tmp;
  cin >> tmp;
  return tmp;
}

int answer(int x) {
  cout << "! " << x << endl;
}

inline int f(int x) {
  p[0] = 1;
  FOR(i, 1, 10) p[i] = mul(p[i - 1], x);
  int ret = 0;
  REP(i, 11) ret = add(ret, mul(coeff[i], p[i]));
  return ret;
}

int main() {
  int n = 11;
  REP(i, 11) {
    A[i][n] = ask(i);
    A[i][0] = 1;
    FOR(j, 1, 10) A[i][j] = mul(A[i][j - 1], i);
  }
  gauss(A, n);
  REP(i, 11) coeff[i] = A[i][n];
  REP(i, MOD) if (!f(i)) {
    answer(i);
    return 0;
  }
  answer(-1);
}