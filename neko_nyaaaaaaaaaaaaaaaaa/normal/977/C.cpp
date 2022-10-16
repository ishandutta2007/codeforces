#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0);

      int n, k;
      cin >> n >> k;

      if (k == n) {cout << "1000000000"; return 0;}

      vector<int> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }
      sort(a.begin(), a.end());

      if (k == 0) {
            cout << (a[0] == 1 ? -1 : 1);
            return 0;
      }
      if (a[k] == a[k-1]) {
            cout << -1;
            return 0;
      }
      cout << a[k-1];

      return 0;
}