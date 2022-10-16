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

vector<vector<int>> mul(const vector<vector<int>> &A, const vector<vector<int>> &B) {
  vector<vector<int>> ret(3, vector<int>(3));
  REP(i, 3) REP(j, 3) REP(k, 3) ret[i][j] = (ret[i][j] + ll(A[i][k]) * B[k][j]) % (MOD - 1);
  return ret;
}

vector<vector<int>> pow(vector<vector<int>> A, ll pw) {
  vector<vector<int>> ret(3, vector<int>(3));
  ret[0][0] = ret[1][1] = ret[2][2] = 1;
  while (pw) {
    if (pw & 1) ret = mul(ret, A);
    A = mul(A, A);
    pw >>= 1;
  }
  return ret;
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

ll n;
int f[5], C;

int main() {
  cin >> n >> f[1] >> f[2] >> f[3] >> C;
  vector<vector<int>> A(3, vector<int>(3));
  A[0][0] = A[0][1] = A[0][2] = 1;
  A[1][0] = A[2][1] = 1;
  A = pow(A, n - 3);
  int a = A[0][0], b = A[0][1], c = A[0][2];
  int ans = mul(mul(pow_mod(f[3], a), pow_mod(f[2], b)), pow_mod(f[1], c));
  ans = mul(ans, pow_mod(C, (3 * ll(a) + 2 * b + c) % (MOD - 1)));
  n %= (MOD - 1);
  ans = mul(ans, pow_mod(C, (MOD - 2) * n % (MOD - 1)));
  cout << ans;
}