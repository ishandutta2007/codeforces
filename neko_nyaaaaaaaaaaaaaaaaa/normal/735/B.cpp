#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      int n, x, y;
      cin >> n >> x >> y;
      vector<ll> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }
      sort(a.begin(), a.end(), greater<ll>());
      if (x > y) swap(x, y);
      
      int tmp1 = x, tmp2 = y;
      
      ll ans1 = 0, ans2 = 0;
      int i = 0;
      for (; x--; i++) {
            ans1 += a[i];
      }
      for (; y--; i++) {
            ans2 += a[i];
      }
      
      cout << fixed << setprecision(12) << ans1*1.0/tmp1 + ans2*1.0/tmp2;
}