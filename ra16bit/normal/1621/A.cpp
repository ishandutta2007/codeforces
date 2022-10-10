#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,j;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    if (m>(n+1)/2) { puts("-1"); continue; }
    for (i=0; i<n; i++, putchar('\n')) for (j=0; j<n; j++) {
      if (i==j && i%2==0 && i/2<m) putchar('R'); else putchar('.');
    }
  }
  return 0;
}