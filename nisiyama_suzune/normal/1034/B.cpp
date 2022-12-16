#include <bits/stdc++.h>

int main () {
  long long N, M;
  std::cin >> N >> M;
  if (N > M) std::swap (N, M);
  if (N <= 2 && M <= 2) std::cout << "0\n";
  else if (N == 1) {
    if (M % 6 == 4) std::cout << (M / 6 * 6) + 2 << "\n";
    else if (M % 6 == 5) std::cout << (M / 6 * 6) + 4 << "\n";
    else std::cout << (M / 6 * 6) << "\n";
  } else if (N == 2 && M == 3) std::cout << "4\n";
  else if (N == 2 && M == 7) std::cout << "12\n";
  else std::cout << (N * M / 2) * 2 << "\n";
}