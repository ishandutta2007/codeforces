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

const int maxn = 412;

int n, M;
int f[maxn][maxn], C[maxn][maxn], p[maxn];

int add(int a, int b) {
  a += b;
  if (a >= M) a -= M;
  return a;
}

int mul(int a, int b) {
  return ll(a) * b % M;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> M;
  C[0][0] = p[0] = 1;
  FOR(i, 1, n) {
    C[i][0] = 1;
    FOR(j, 1, i) C[i][j] = add(C[i - 1][j], C[i - 1][j - 1]);
    p[i] = add(p[i - 1], p[i - 1]);
  }
  f[0][0] = 1;
  REP(i, n) REP(j, i + 1) FOR(k, 1, n - i) {
    int inc = mul(f[i][j], mul(p[k - 1], C[j + k][k]));
    f[i + k + 1][j + k] = add(f[i + k + 1][j + k], inc);
  }
  int ans = 0;
  FOR(i, 1, n) ans = add(ans, f[n + 1][i]);
  cout << ans;
}