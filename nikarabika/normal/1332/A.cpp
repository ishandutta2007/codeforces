//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

bool ok(int l, int r, int x, int x1, int x2) {
  int d = r - l;
  if (d != 0) {
    x += d;
    return x1 <= x and x <= x2;
  }
  if (d == 0 and l == 0)
    return true;
  return x2 - x1;
}

int solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x, y, x1, y1, x2, y2;
  cin >> x >> y >> x1 >> y1 >> x2 >> y2;
  if (ok(a, b, x, x1, x2) and ok(c, d, y, y1, y2))
    cout << "YES\n";
  else
    cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}