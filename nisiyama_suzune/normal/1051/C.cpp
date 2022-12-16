#include <bits/stdc++.h>

int N;
int val[110], cnt[110];

int main () {
  std::ios::sync_with_stdio (0);
  std::cin >> N; for (int i = 0; i < N; ++i) { std::cin >> val[i]; ++cnt[val[i]]; }
  int ones = 0, multi = 0;
  for (int i = 1; i <= 100; ++i) if (cnt[i] == 1) ++ones;
  for (int i = 1; i <= 100; ++i) if (cnt[i] >= 3) ++multi;
  if ((ones & 1) && multi == 0) { std::cout << "NO\n"; return 0; }
  std::cout << "YES\n";
  for (int i = 0, sgn = 0, flag = 0; i < N; ++i) {
    if (cnt[val[i]] == 1) std::cout << char ('A' + sgn), sgn ^= 1;
    else if (cnt[val[i]] >= 3 && (ones & 1) && flag == 0) std::cout << "B", flag = 1;
    else std::cout << "A";
  }
  std::cout << "\n";
}