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

void solve() {
  ll l, r;
  int n;
  scanf("%d%lld%lld", &n, &l, &r);
  l--, r--;
  int st = 1;
  while (st < n && l >= 2 * (n - st)) {
    l -= 2 * (n - st);
    r -= 2 * (n - st);
    st++;
  }
  vector<int> ans;
  auto get = [&]() {
    FOR(i, st + 1, n) {
      ans.eb(st);
      ans.eb(i);
    }
    st++;
  };
  while (st < n && ans.size() <= r) get();
  ans.eb(1);
  FOR(i, l, r) printf("%d ", ans[i]);
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}