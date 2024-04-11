#include <bits/stdc++.h>
using namespace std;

int main() {
      int n, m;
      cin >> n >> m;
      n--;
      vector<int> a(m);
      for (int i = 0; i < m; i++) {
            cin >> a[i];
      }
      sort(a.begin(), a.end());
      int ans = 1000000;
      for (int i = 0; i < m-n; i++) {
            if (abs(a[i+n] - a[i]) < ans) {ans = abs(a[i+n] - a[i]);}
      }
      cout << ans;
}