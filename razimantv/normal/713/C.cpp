#include <algorithm>
#include <cstring>
#include <iostream>

const int NMAX=3001;
const long long INF = 1000000000000000ll;

long long a[NMAX], acopy[NMAX], best[NMAX][NMAX];

int main() {
  int N;
  std::cin >> N;
  for (int i = 0; i < N; ++i) {
    std::cin >> a[i];
    a[i] -= i;
    acopy[i] = a[i];
  }
  std::sort(a, a+N);

  for (int i = 0; i < N; ++i) {
    best[i+1][0] = best[i][0] + std::abs(acopy[i] - a[0]);
    for (int j = 1; j < N; ++j) {
      best[i+1][j] =
          std::min(best[i+1][j-1], best[i][j] + std::abs(acopy[i] - a[j]));
    }
  }
  std::cout << best[N][N-1] << std::endl;
  return 0;
}