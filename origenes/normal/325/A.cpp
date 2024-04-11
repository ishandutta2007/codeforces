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
  int n;
  ll x1, x2, y1, y2, s = 0;
  ll mn_x = 1e9, mn_y = 1e9, mx_x = -1, mx_y = -1;
  cin >> n;
  REP(i, n) {
    cin >> x1 >> y1 >> x2 >> y2;
    chkmin(mn_x, x1);
    chkmin(mn_y, y1);
    chkmax(mx_x, x2);
    chkmax(mx_y, y2);
    s += (x2 - x1) * (y2 - y1);
  }
  ll t = (mx_x - mn_x) * (mx_y - mn_y);
  puts (s == t && mx_y - mn_y == mx_x - mn_x ? "YES" : "NO");
}