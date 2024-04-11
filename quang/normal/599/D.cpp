#include <bits/stdc++.h>

using namespace std;

pair<long long, long long> res[1000100];
long long x;
int top = 0;

int main() {
  scanf("%I64d", &x);
  int cur = 0;
  long long sum = 0, sum2 = 0;
  while (1) {
    cur++;
    sum += 1ll * cur * cur;
    sum2 += cur;
    long long foo = x - sum;
    if (foo < 0) {
      break;
    }
    if (foo % sum2 == 0) {
      long long delta = foo / sum2;
      res[top++] = make_pair(cur, delta + cur);
      if (cur != delta + cur) {
        res[top++] = make_pair(delta + cur, cur);
      }
    }
  }
  printf("%d\n", top);
  sort(res, res + top);
  for (int i = 0; i < top; i++) {
    printf("%I64d %I64d\n", res[i].first, res[i].second);
  }
  return 0;
}