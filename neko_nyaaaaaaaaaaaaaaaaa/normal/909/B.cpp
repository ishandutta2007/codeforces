#include <bits/stdc++.h>
using namespace std;

int main() {
      long long n;
      cin >> n;
      long long ans = 0;
      while (n > 0) {
            ans += n;
            n -= 2;
      }
      cout << ans;
}