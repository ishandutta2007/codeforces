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

const int maxn = 35;

int n, q;
ll k, a[maxn][maxn];

void solve() {
  cout << "1 1" << endl;
  int r = 1, c = 1;
  REP(i, 2 * n - 2) {
    ll nxt = k & (1LL << i + 1);
    if (r < n && a[r + 1][c] == nxt) r++;
    else c++;
    cout << r << ' ' << c << endl;
  }
  cout << endl;
}

int main() {
  cin >> n;
  FOR(i, 1, n) FOR(j, 1, n) a[i][j] = (i & 1) * (1LL << j + i - 2);
  FOR(i, 1, n) {
    FOR(j, 1, n) cout << a[i][j] << ' ';
    cout << endl;
  }
  cin >> q;
  while (q--) {
    cin >> k;
    solve();
  }
}