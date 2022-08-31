#include <iostream>
#include <vector>

int main() {
  std::vector<long long> primes;
  for (int i = 2; i < 1000; ++i) {
    bool flag = true;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        flag = false;
        break;
      }
    }
    if (flag) primes.push_back(i);
  }

  int N;
  std::cin >> N;

  if(N == 2) {
    std::cout << -1 << std::endl;
    return 0;
  }

  int cnt = 0, lim = 1;
  while (lim < N) cnt++, lim <<= 1;

  std::vector<long long> out(lim, 1);
  for (int i = 0; i < cnt; ++i) {
    for (int j = 0; j < lim; ++j) {
      if (j & (1 << i))
        out[j] *= primes[2 * i];
      else
        out[j] *= primes[2 * i + 1];
    }
  }

  for (int i = 0; i < lim / 2; ++i) {
    out[i] *= primes[i + 2 * cnt];
    out[i ^ (lim-1)] *= primes[i + 2 * cnt];
  }

  for (int i = 0; i < N; ++i) {
    std::cout << out[i] << std::endl;
  }

  return 0;
}