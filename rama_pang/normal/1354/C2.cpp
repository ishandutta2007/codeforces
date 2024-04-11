#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cout << fixed << setprecision(12);


  int T;
  cin >> T;
  while (T--) {
    const double pi = acos(-1);
    int n;
    cin >> n;
    if (n % 2 == 0) {
      n *= 2;
      double alpha = pi / n;
      double r = 1.00 / (2.00 * sin(alpha));
      double s = r * cos(alpha);
      cout << 2 * s << "\n";
    } else {
      int k = n;
      n *= 2;
      double alpha = pi / n;
      double r = 1.00 / (2.00 * sin(alpha));
      double s = r * cos(alpha);
      double ans = 1.00 / sin(alpha / 2);
      cout << ans / 2 << "\n";
      // cout << 2 * ans << "\n";
      // cout << r << " ";
      // cout << s << " " << r << "\n";
      // double rat = (1 + sqrt(3)) / 2;
      // double rat = 1.498835;
      // cout << s << "\n";
      // cout << (s / 2) + rat * r << "\n";
      // cout << (16 * s + 47 * r) / 31.5 << "\n";
    }
  }
}