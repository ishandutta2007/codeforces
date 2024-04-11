#include <cstdio>
#include <algorithm>

using namespace std;

#define LL long long

const int MAXN = (int) 1e5 + 10;

int n, m;
int a[MAXN];

LL calc(int d) {
  LL res = 0;
  for (; d < m; d *= 2)
    res += m - d;
   
  return res;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  
  int g = a[0] - 1;
  for (int i = 1; i < n; i++)
    g = __gcd(a[i] - 1, g);
  
  while (g % 2 == 0) g /= 2;
  
  LL ans = 0;
  for (int d = 1; d * d <= g; d++) {
    if  (g % d != 0) continue;
    
    ans += calc(d);
    
    if  (d * d != g)
      ans += calc(g / d);
  }
  
  printf("%I64d\n", ans);
  return 0;
}