#include <bits/stdc++.h>

const int SIZE = 16000000;

int prime[SIZE], psize;
int is_co[SIZE], dis[SIZE];
int N, A[310000];
int cnt[SIZE];

int main () {
  for (int i = 2; i < SIZE; ++i) {
    if (!is_co[i]) prime[psize++] = i, dis[i] = i;
    for (int j = 0; 1ll * i * prime[j] < SIZE; ++j) {
      is_co[i * prime[j]] = true; dis[i * prime[j]] = prime[j];
      if (i % prime[j] == 0) break;
    }
  }
  std::ios::sync_with_stdio (0);
  std::cin >> N; for (int i = 0; i < N; ++i) std::cin >> A[i];
  int gcd = A[0];
  for (int i = 0; i < N; ++i) gcd = std::__gcd (gcd, A[i]);
  for (int i = 0; i < N; ++i) A[i] /= gcd;
  for (int i = 0; i < N; ++i)
    while (A[i] != 1) { int cur = dis[A[i]]; ++cnt[cur]; while (A[i] % cur == 0) A[i] /= cur; }
  int ans = -1;
  for (int i = 0; i < psize; ++i)
    if (cnt[prime[i]] > 0 && cnt[prime[i]] < N) ans = std::max (ans, cnt[prime[i]]);
  if (ans == -1) std::cout << "-1\n";
  else std::cout << N - ans << "\n";
}