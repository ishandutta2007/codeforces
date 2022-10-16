#include <bits/stdc++.h>
using namespace std;

int main() {
      int a, b, c, n;
      cin >> n >> a >> b >> c;
      int ans = 0;
      for (int i = 0; a*i <= n; i++) {
            for (int j = 0; a*i + b*j <= n; j++) {
                  int k = n - a*i - b*j;
                  if (k % c == 0) {
                        k /= c;
                        if (i+k+j > ans) {ans = i+k+j;}
                  }
            }
      }
      cout << ans;
}