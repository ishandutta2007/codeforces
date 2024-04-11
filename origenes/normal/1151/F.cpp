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
const int maxn = 112;

int n, k, c0, ini[maxn];

inline int add(int a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
  return a;
}

inline int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int pow_mod(int a, int pw) {
  int ret = 1;
  while (pw) {
    if (pw & 1) ret = mul(ret, a);
    a = mul(a, a);
    pw >>= 1;
  }
  return ret;
}

vector<vector<int>> mul(const vector<vector<int>> &a, const vector<vector<int>> &b) {
  vector<vector<int>> ret(c0 + 1, vector<int>(c0 + 1));
  REP(i, c0 + 1) REP(j, c0 + 1) REP(k, c0 + 1)
    ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
  return ret;
}

vector<vector<int>> pow(vector<vector<int>> a, int k) {
  vector<vector<int>> ret(c0 + 1, vector<int>(c0 + 1));
  REP(i, c0 + 1) ret[i][i] = 1;
  while (k) {
    if (k & 1) ret = mul(ret, a);
    a = mul(a, a);
    k >>= 1;
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) {
    scanf("%d", ini + i);
    if (!ini[i]) c0++;
  }
  vector<vector<int>> A(c0 + 1, vector<int>(c0 + 1));
  int iv = pow_mod(n * (n - 1) / 2, MOD - 2);
  REP(i, c0 + 1) {
    int one = c0 - i, a0 = c0 - i, a1 = n - c0 - a0;
    if (a1 < 0) continue;
    if (i && a1 - 1 >= 0) A[i][i - 1] = mul(mul(i, a1), iv);
    if (i != c0) A[i][i + 1] = mul(mul(one, a0), iv);
    A[i][i] = add(A[i][i], c0 * (c0 - 1) / 2);           // fi fi
    A[i][i] = add(A[i][i], (n - c0) * (n - c0 - 1) / 2); // se se
    A[i][i] = add(A[i][i], mul(i, a0));                       // zero zero
    A[i][i] = add(A[i][i], mul(one, a1));                     // one one
    A[i][i] = mul(A[i][i], iv);
  }
//  REP(i, c0 + 1) {
//    REP(j, c0 + 1) cerr << A[i][j] << ' ';
//    cerr << endl;
//  }
  A = pow(A, k);
//  REP(i, c0 + 1) {
//    REP(j, c0 + 1) cerr << A[i][j] << ' ';
//    cerr << endl;
//  }
  int st = 0;
  FOR(i, 1, c0) if (!ini[i]) st++;
  printf("%d", A[st][c0]);
}