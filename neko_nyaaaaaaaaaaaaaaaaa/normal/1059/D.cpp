#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<long double> x(100001), y(100001);

long double read() {
      int b; cin >> b;
      return b;
}

int check(long double mid) {
      long double left = -1e18, right = 1e18;
      for (int i = 0; i < n; i++) {
            long double r = mid - y[i];
            long double d = sqrtl(mid*mid - r*r);
            long double lb = x[i] - d;
            long double rb = x[i] + d;
            left = max(left, lb);
            right = min(right, rb);
      }
      return left <= right;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      cin >> n;
      int pos = 0, neg = 0;
      long double lo = 0, hi = 1e18;
      for (int i = 0; i < n; i++) {
            x[i] = read(); y[i] = read();
            if (y[i] > 0) pos = 1;
            if (y[i] < 0) neg = 1;

            lo = max(lo, abs(y[i]));
            y[i] = abs(y[i]);
      }
      if (pos && neg) {cout << -1; return 0;}
      lo /= 2;

      for (int i = 0; i <= 150; i++) {
            long double mid = (lo + hi)/2;
            if (check(mid)) {
                  hi = mid;
            } else {
                  lo = mid;
            }
      }
      cout << fixed << setprecision(12) << lo;

	return 0;
}