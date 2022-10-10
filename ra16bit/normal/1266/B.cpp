#include <bits/stdc++.h>
using namespace std;
int n,i;
long long x;
int main() {
  scanf("%d",&n);
  while (n--) {
    scanf("%I64d",&x);
    for (i=1; i<=6; i++) if (x>=21-i && (x-(21-i))%14==0) {
      puts("YES");
      break;
    }
    if (i>6) puts("NO");
  }
  return 0;
}