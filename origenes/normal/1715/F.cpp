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
  cout << fixed << setprecision(10);
  int n, m;
  cin >> n >> m;
  cout << "? " << 2 * n + 1 << endl;
  REP(i, n) cout << i << ' ' << m << '\n' << i << " 0" << endl;
  cout << n << ' ' << m << endl;
  double x, y;
  cin >> y; y = y * m - 0.5;
  cout << "? " << 2 * m + 1 << endl;
  REP(i, m) cout << n << ' ' << i << '\n' << "0 " << i << endl;
  cout << n << ' ' << m << endl;
  cin >> x; x = x * n - 0.5;
  cout << "! " << x << ' ' << y << endl;
}