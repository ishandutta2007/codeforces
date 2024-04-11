#include <bits/stdc++.h>
#define int long long
using namespace std;

int euclid(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1, y = 0;
    return a;
  }
  int d = euclid(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbPlats;
  cin >> nbPlats;
  vector<int> a(nbPlats), b(nbPlats), diffs(nbPlats);

  int sumA = 0;
  for (int i = 0; i < nbPlats; ++i) {
    cin >> a[i] >> b[i];
    diffs[i] = b[i] - a[i];
    sumA += a[i];
  }
  sort(diffs.rbegin(), diffs.rend());
  vector<int> pref(nbPlats + 1);
  for (int i = 0; i < nbPlats; ++i)
    pref[i + 1] = pref[i] + diffs[i];

  int nbRequetes;
  cin >> nbRequetes;
  for (int iRequete = 0; iRequete < nbRequetes; ++iRequete) {
    int x, y;
    cin >> x >> y;

    int g = gcd(x, y);
    if (nbPlats % g) {
      cout << -1 << '\n';
      continue;
    }
    int x0 = 0, y0 = 0;
    assert(euclid(x, y, x0, y0) == g);
    x0 *= nbPlats / g, y0 *= nbPlats / g;
    assert(x * x0 + y * y0 == nbPlats);

    int dx = y / g;
    int dy = x / g;
    // x0 + k dx >= 0 <=> k * dx >= -x0 <=> k >= ceil(-x0 / dx)
    int lo = ceil((-x0) / (double)dx);
    int up = floor(y0 / (double)dy);
    if (lo > up) {
      cout << -1 << '\n';
      continue;
    }

    auto f = [&](int i) { return sumA + pref[y * (y0 - i * dy)]; };
    int sol = -1e18;
    while (up - lo >= 5) {
      int mid = (lo + up) / 2;
      if (f(mid) < f(mid + 1))
        lo = mid;
      else
        up = mid + 1;
    }
    for (int i = lo; i <= up; ++i)
      sol = max(sol, f(i));
    cout << sol << '\n';
  }
}