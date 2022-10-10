#include <bits/stdc++.h>
using namespace std;
int t,n,i,x;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    if (n%2==0) {
      n/=2;
      x=sqrt(n);
      for (i=x-2; i<=x+2; i++) if (i*i==n) break;
      if (i*i==n) puts("YES"); else if (n%2==0) {
        n/=2;
        x=sqrt(n);
        for (i=x-2; i<=x+2; i++) if (i*i==n) break;
        if (i*i==n) puts("YES"); else puts("NO");
      } else puts("NO");
    } else puts("NO");
    
  }
  return 0;
}