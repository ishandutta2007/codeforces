#include <bits/stdc++.h>

#define fi first
#define se second
#define re return
#define pb push_back

#define F(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define f(i, n) F(i, 0, n)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int run();

int main() {
#ifdef home
  freopen("i", "r", stdin);
  freopen("d", "w", stderr);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  run();

  return 0;
}

ll a[100500];

int run() {
  ld ans = 1;

  int n;
  cin >> n;
  ll u;
  cin >> u;
  f(i, n) {
    cin >> a[i];
  }

  bool ok = false;

  f(i, n - 2) {
    int j = i + 1;
    int k = upper_bound(a, a + n, a[i] + u) - a - 1;
    if (k <= j) {
      continue;
    }
    ok = true;
    ans = min(ans, (long double)1 * (a[j] - a[i]) / (a[k] - a[i]));
  }

  if (!ok) {
    cout << -1;
    re 0;
  }

  cout << setprecision(20) << 1 - ans << '\n';

  return 0;
}