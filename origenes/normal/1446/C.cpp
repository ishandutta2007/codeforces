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

const int maxn = 212345;

int n, ans;
int a[maxn];

int solve(int b, int l, int r) {
  if (b == -1) return r - l + 1;
  int d = r + 1;
  FOR(i, l, r) if ((a[i] & (1 << b)) == 0) {
    d = i;
    break;
  }
  if (d == l || d == r + 1) return solve(b - 1, l, r);
  int c1 = solve(b - 1, l, d - 1);
  int c2 = solve(b - 1, d, r);
  int loss = max(min(c1, c2) - 1, 0);
  ans += loss;
  return c1 + c2 - loss;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n;
  FOR(i, 1, n) cin >> a[i];
  sort(a + 1, a + n + 1, greater<>());
  solve(29, 1, n);
  cout << ans;
}