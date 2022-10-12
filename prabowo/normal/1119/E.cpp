#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  scanf("%d", &n);
  long long ans = 0;
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    
    int p = min(cur, a / 2);
    a -= p*2, cur -= p, ans += p;
    
    ans += a / 3, a %= 3;
    cur += a;
  }

  printf("%lld\n", ans);
  return 0;
}