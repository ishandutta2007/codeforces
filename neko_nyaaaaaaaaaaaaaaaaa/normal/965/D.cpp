#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0);
      
      int n, k;
      cin >> n >> k;
      vector<ll> a(n+1);
      for (int i = 1; i < n; i++) {
            cin >> a[i];
            a[i] += a[i-1];
      }
      
      ll ans = 1e12;
      for (int i = k; i < n; i++) {
            ans = min(ans, a[i] - a[i-k]);
      }
      cout << ans;
      
      return 0;
}