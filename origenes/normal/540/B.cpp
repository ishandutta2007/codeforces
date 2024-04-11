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

int n, k, p, x, y;

int main() {
  cin >> n >> k >> p >> x >> y;
  int cnt = 0, sum = 0;
  REP(i, k) {
    int a; cin >> a;
    if (a < y) cnt++;
    sum += a;
  }
  if (cnt > (n - 1) / 2) {
    cout << -1;
    return 0;
  }
  int L = min(n - k, (n - 1) / 2 - cnt);
  int R = n - k - L;
  if (L + y * R > x - sum) cout << -1;
  else {
    vector<int> ans;
    REP(i, L) ans.eb(1);
    REP(i, R) ans.eb(y);
    for (auto now : ans) cout << now << ' ';
  }
}