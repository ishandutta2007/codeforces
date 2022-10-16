#include <bits/stdc++.h>
using namespace std;

int main() {
      long long a, b;
      cin >> a >> b;
      long long ans = 1;
      for (long long i = 1; i <= min(a, b); i++) {
            ans *= i;
      }
      cout << ans;
}