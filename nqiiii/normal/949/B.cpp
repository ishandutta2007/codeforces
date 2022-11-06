#include <cstdio>
typedef long long Long;
Long n;
int q;
Long Solve(Long l, Long r, Long k) {
  Long left = (r - l) / 2 + 1;
  if (k & 1) return l + k / 2;
  else if (left * 2 != r - l + 1){
    k = k / 2;
    if (k == 1) k = (r - l + 1 - left);
    else --k;
    return Solve(l + left, r, k);
  } else Solve(l + left, r, k / 2);
}
int main() {
  scanf("%lld%d", &n, &q);
  for (int i = 1; i <= q; ++i) {
    Long x; scanf("%lld", &x);
    printf("%lld\n", Solve(1, n, x));
  }
}