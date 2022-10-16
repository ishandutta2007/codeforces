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
using ull = unsigned long long;
const ull MOD = 1009;

int n;
ull m, a[maxn], d[maxn], pre[maxn], suf[maxn], pw[maxn];

inline bool check(int l, int r) {
  return pre[r] - pre[l - 1] * pw[r - l + 1] == suf[l] - suf[r + 1] * pw[r - l + 1];
}

int main() {
  cin >> n >> m;
  FOR(i, 1, n) cin >> a[i];
  FOR(i, 1, n - 1) d[i] = a[i + 1] - a[i];
  pw[0] = 1;
  FOR(i, 1, n) pw[i] = pw[i - 1] * MOD;
  FOR(i, 1, n - 1) pre[i] = pre[i - 1] * MOD + d[i];
  ROF(i, n - 1, 1) suf[i] = suf[i + 1] * MOD + d[i];
  vector<ull> ans;
  FOR(i, 1, n) {
    bool good = true;
    if (i != 1) good &= check(1, i - 1);
    if (i != n) {
      good &= (a[1] + a[i] + m == a[i + 1] + a[n]);
      if (i != n - 1) good &= check(i + 1, n - 1);
    }
    if (good) ans.eb((a[1] + a[i]) % m);
  }
  sort(all(ans));
  uni(ans);
  cout << ans.size() << '\n';
  for (auto it : ans) cout << it << ' ';
}