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
  int n;
  scanf("%d", &n);
  set<int> facs{n};
  for (int i = 2; sqr(i) <= n; i++) if (n % i == 0) {
    facs.emplace(i);
    facs.emplace(n / i);
  }
  vector<int> ans;
  while (!facs.empty()) {
    if (ans.empty()) {
      ans.eb(*facs.begin());
      facs.erase(facs.begin());
    } else {
      for (auto x : facs) if (gcd(x, ans.back()) > 1) {
        ans.eb(x);
        facs.erase(x);
        break;
      }
    }
  }
  for (auto x : ans) printf("%d ", x);
  printf("\n%d\n", gcd(ans.front(), ans.back()) == 1);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}