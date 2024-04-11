#include <cstdio>
#include <vector>
using namespace std;

vector<bool> f(312345678);

int main() {
  int l, r;
  scanf("%d%d", &l, &r);
  f[1] = true;
  for (int i = 2; i * i <= r; i++) {
    if (f[i]) continue;
    for (int j = i * i; j <= r; j += i) {
      f[j] = true;
    }
  }
  int ans = 0;
  if (l <= 2 && 2 <= r) ++ans;
  for (int i = l; i <= r; i++) if ((i & 3) == 1 && !f[i]) ++ans;
  printf("%d\n", ans);
}