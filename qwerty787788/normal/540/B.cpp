#include <bits/stdc++.h>

int main() {
  int n, k, p, x, y;
  std::cin >> n >> k >> p >> x >> y;
  int sum = 0, cnt_less = 0;
  int tmp;
  for (int i = 0; i < k; i++) {
    std::cin >> tmp;
    sum += tmp;
    if (tmp < y) cnt_less++;
  }
  if (cnt_less > n / 2) {
    std::cout << -1 << std::endl;
    return 0;
  } 
  int more_ones = n / 2 - cnt_less;
  if (more_ones > n - k) more_ones = n - k;
  for (int i = 0; i < more_ones; i++) sum += 1;
  for (int i = 0; i < n - k - more_ones; i++) sum += y;
  if (sum > x) {
    std::cout << -1 << std::endl;
    return 0;
  }
  for (int i = 0; i < more_ones; i++) std::cout << "1 ";
  for (int i = 0; i < n - k - more_ones; i++) std::cout << y << " ";
  std::cout << std::endl;
  return 0;
}