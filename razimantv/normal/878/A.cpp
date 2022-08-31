// Bad practice, just doing this for competitive programming!
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  std::cin >> N;
  int zeros = 0, ones = 1023;
  for (int i = 0; i < N; ++i) {
    string op;
    int x;
    std::cin >> op >> x;
    if (op == "|") zeros |= x, ones |= x;
    else if (op == "&") zeros &= x, ones &= x;
    else zeros ^= x, ones ^= x;
  }

  // Map from results for 0 and 1 to or and xor
  int or_bit[4] = {1, 0, 0, 1}, xor_bit[4] = {1, 0, 1, 0};
  int or_val = 0, xor_val = 0;
  for (int i = 0; i < 10; ++i, zeros >>= 1, ones >>= 1) {
    int cur = ((zeros & 1) << 1) | (ones & 1);
    or_val |= (or_bit[cur] << i);
    xor_val |= (xor_bit[cur] << i);
  }

  std::cout << 2 << "\n";
  std::cout << "| " << or_val << "\n";
  std::cout << "^ " << xor_val << "\n";
  return 0;
}