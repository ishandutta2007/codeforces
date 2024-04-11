#include <cstdio>
#include <algorithm>

int main() {
  long long a, b, c;
  scanf("%I64d%I64d%I64d", &a, &b, &c);
  long long mx = std::max(std::max(a, b), c);
  if (mx <= 2 * (a + b + c - mx)) printf("%I64d\n", (a + b + c) / 3); else {
    printf("%I64d\n", (a + b + c - mx));
  }
}