#include <bits/stdc++.h>
using namespace std;

int main() {
      long long n;
      cin >> n;
      long long ans = 1;
      for (long long i = 0; i < n; i++) {
      	ans *= 2;
      	if (ans == 8192) {ans-=100;}
      }
      cout << ans;
      return 0;
}