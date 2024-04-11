#include <bits/stdc++.h>
using namespace std;

int main() {
      long long a, b;
      cin >> a >> b;
      long long ans = 0;
      while (1) {
            if (a < b) {swap(a, b);}
            if (b == 0) {break;}
            ans += a/b;
            a %= b;
      }
      cout << ans;
}