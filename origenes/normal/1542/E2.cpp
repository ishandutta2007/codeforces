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

const int maxn = 512;
const int BASE = 250 * 500;

int n, MOD;
int P[maxn], f[2][maxn * maxn];

int mul(int a, int b) {
  return ll(a) * b % MOD;
}

int add(int a, int b) {
  return (a + b) % MOD;
}

void update(int &a, int b) {
  a = add(a, b);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> MOD;
  P[0] = 1;
  FOR(i, 1, n) P[i] = mul(P[i - 1], n - i + 1);
  f[0][BASE] = 1;
  int ans = 0;
  FOR(i, 1, n - 1) {
    int now = i & 1, pre = 1 - now;
    reset(f[now], 0);
    int diff = sqr(i + 1) / 2;
    FOR(j, BASE - diff, BASE + diff) {
      update(f[now][j + i + 1], f[pre][j]);
      update(f[now][j - i + 1], f[pre][j]);
      update(f[now][j + 1], mul(f[pre][j], MOD - 2));
    }
    REP(_, 2) {
      ROF(j, BASE + diff, BASE - diff) update(f[now][j], f[now][j + 1]);
      FOR(j, BASE - diff, BASE + diff) f[now][j] = f[now][j + 1];
    }
    vector<int> suf(maxn * maxn);
    ROF(j, diff, 0) suf[j] = add(suf[j + 1], f[now][BASE + j]);
    REP(ii, i + 1) FOR(jj, ii + 1, i) update(ans, mul(P[n - i - 1], suf[jj - ii + 1]));
  }
  cout << ans;
}