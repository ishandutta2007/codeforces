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

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, k;
  cin >> n >> k;
  vector<int> b(n);
  vector<bool> ans(1 << 20);
  REP(i, n) cin >> b[i];
  REP(i, n) {
    ll sum = 1;
    FOR(j, i, n - 1) {
      if (i == j) sum = b[j];
      else {
        if (b[j] >= 20) break;
        sum *= 1 << b[j];
      }
      if (sum >= 1 << 20) break;
      int p = n - (j - i + 1) - 2, q = k - 2;
      if (i == 0) p++, q++;
      if (j == n - 1) p++, q++;
      if (p >= q && (p == 0 || (q > 0 && ((p - 1) | (q - 1)) == p - 1))) ans[sum] = !ans[sum];
    }
  }
  bool fi = false;
  ROF(i, (1 << 20) - 1, 0) {
    if (fi || ans[i]) cout << ans[i];
    fi |= ans[i];
  }
  if (!fi) cout << 0;
}