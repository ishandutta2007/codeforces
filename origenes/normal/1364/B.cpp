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
int p[maxn];

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", p + i);
  vector<int> ans = {p[1], p[2]};
  FOR(i, 3, n) {
    if ((p[i] > ans.back() && ans.back() > ans[ans.size() - 2]) || (p[i] < ans.back() && ans.back() < ans[ans.size() - 2]))
      ans.pop_back();
    ans.eb(p[i]);
  }
  printf("%lu\n", ans.size());
  for (auto x : ans) printf("%d ", x);
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}