#include <bits/stdc++.h>
using namespace std;

int main() {
      int n, k, t;
      cin >> n >> k >> t;
      if (t <= k) {cout << t; return 0;}
      if (t > n) {
            cout << k - (t-n); return 0;
      }
      cout << k; return 0;
}