#include <bits/stdc++.h>

int main () {
  std::ios::sync_with_stdio (0);
  long long l, r; std::cin >> l >> r;
  std::cout << "YES\n";
  for (long long i = l; i < r; i += 2) std::cout << i << " " << i + 1 << "\n";
}