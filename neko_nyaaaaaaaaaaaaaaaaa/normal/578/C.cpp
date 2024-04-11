#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<double> a;

double read() {
      int x; cin >> x; return x;
}

double f(double x) {
      double ans = 0;
      double mx = 0, mn = 0, sum = 0;
      for (int i = 0; i < n; i++) {
            sum += a[i] - x;
            ans = max(ans, max(abs(sum - mn), abs(sum - mx)));
            mx = max(mx, sum);
            mn = min(mn, sum);
      }
      return ans;
}

double ternary_search(double l, double r) {
      for (int i = 0; i <= 400; i++) {
            double m1 = l + (r - l)/3;
            double m2 = r - (r - l)/3;
            double f1 = f(m1);
            double f2 = f(m2);

            if (f1 > f2) {
                  l = m1;
            } else {
                  r = m2;
            }
      }
      return f(l);
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n; a.resize(n);
      for (int i = 0; i < n; i++) {
            a[i] = read();
      }

      cout << fixed << setprecision(12) << ternary_search(-200000, 200000);

      return 0;
}