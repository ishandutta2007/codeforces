#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }
      sort(a.begin(), a.end());
      int ans = a[n-1] - a[0] + 1;
      cout << ans - n;

      return 0;
}