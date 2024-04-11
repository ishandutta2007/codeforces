#include <bits/stdc++.h>
using namespace std;

int n;

bool isPrime(int n) {
  for (int i = 2; i*i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}

int solve() {
  scanf("%d", &n);

  if (n == 1) printf("FastestFinger\n");
  else if (n == 2) printf("Ashishgup\n");
  else if (n % 2 == 0 && n % 4 != 0) {
    n /= 2;
    if (isPrime(n)) printf("FastestFinger\n");
    else printf("Ashishgup\n");
  } else {
    while (n % 2 == 0) n /= 2;
    if (n > 1) printf("Ashishgup\n");
    else printf("FastestFinger\n");
  }
  
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}