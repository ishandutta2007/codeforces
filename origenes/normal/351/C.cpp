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

const int maxn = 25;

vector<vector<ll>> operator*(const vector<vector<ll>> &a, const vector<vector<ll>> &b) {
  vector<vector<ll>> ret(a.size(), vector<ll>(a.size(), 1e18));
  int n = a.size();
  REP(i, n) REP(j, n) REP(k, n) chkmin(ret[i][j], a[i][k] + b[k][j]);
  return ret;
}

vector<vector<ll>> pow(vector<vector<ll>> a, int pw) {
  auto ret = a;
  int n = a.size();
  REP(i, n) REP(j, n) ret[i][j] = i == j ? 0 : 1e18;
  while (pw) {
    if (pw & 1) ret = ret * a;
    a = a * a;
    pw >>= 1;
  }
  return ret;
}

int n, m;
int a[maxn], b[maxn];

int main() {
  scanf("%d%d", &n, &m);
  REP(i, n) scanf("%d", a + i);
  REP(i, n) scanf("%d", b + i);
  vector<vector<ll>> f(2 * n + 1, vector<ll>(2 * n + 1, 1e18));
  f[0][0] = 0;
  vector<vector<ll>> A(2 * n + 1, vector<ll>(2 * n + 1, 1e18));
  REP(i, 2 * n + 1) A[i][i] = 0;
  REP(i, n) {
    vector<vector<ll>> g(2 * n + 1, vector<ll>(2 * n + 1, 1e18));
    REP(j, 2 * n + 1) {
      if (j) g[j - 1][j] = a[i];
      if (j != 2 * n) g[j + 1][j] = b[i];
    }
    A = A * g;
  }
  f = f * pow(A, m);
  printf("%lld", f[0][0]);
}