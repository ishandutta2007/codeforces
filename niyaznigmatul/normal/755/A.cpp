#include <bits/stdc++.h>

bool isPrime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= 1000; i++) {
    if (!isPrime(i * n + 1)) {
      printf("%d\n", i);
      return 0;
    }
  }
  
}