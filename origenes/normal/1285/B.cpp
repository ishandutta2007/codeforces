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

const int maxn = 112345;

int n;
ll a[maxn], pre[maxn], mx[maxn];

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%lld", a + i);
  FOR(i, 1, n) pre[i] = pre[i - 1] + a[i];
  mx[n] = pre[n];
  ROF(i, n - 1, 1) mx[i] = max(pre[i], mx[i + 1]);
  ll ans2 = a[1];
  FOR(i, 1, n - 1) chkmax(ans2, pre[i]);
  FOR(i, 2, n) chkmax(ans2, mx[i] - pre[i - 1]);
  if (ans2 >= pre[n]) puts("NO");
  else puts("YES");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}