#include <bits/stdc++.h>
using namespace std;

int main() {
      int n, x;
      cin >> n;
      int ans1 = 0, ans2 = 0;
      for (int i = 0; i < n; i++) {
            cin >> x;
            ans1 ^= x;
      }
      for (int i = 1; i < n; i++) {
            cin >> x;
            ans1 ^= x;
            ans2 ^= x;
      }
      cout << ans1 << endl;
      for (int i = 2; i < n; i++) {
            cin >> x;
            ans2 ^= x;
      }
      cout << ans2;
}