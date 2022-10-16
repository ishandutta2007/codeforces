#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<long double> point;
#define x real
#define y imag

ld get(point a, point b, point c) {
      ld d1 = abs(a-b);
      ld d2 = abs(b-c);
      ld d3 = abs(c-a);

      ld s = (d1+d2+d3)/2;

      ld ar = sqrt(s*(s - d1)*(s - d2)*(s - d3))*2;

      return ar/d1;
}

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<point> a(n);
      for (int i = 0; i < n; i++) {
            long double p, q; cin >> p >> q;
            a[i] = point(p, q);
      }
      a.push_back(a[0]); a.push_back(a[1]);

      ld ans = 1e18;
      for (int i = 1; i <= n; i++) {
            ans = min(ans, get(a[i-1], a[i+1], a[i]));
      }
      cout << fixed << setprecision(8) << ans/2;

	return 0;
}