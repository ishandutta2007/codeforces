#include <bits/stdc++.h>
using namespace std;
int t,n,x,y,i,j,k;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d%d",&n,&x,&y);
    if (x+y>n-2) { puts("-1"); continue; }
    if (x>y) {
      if (x>y+1) { puts("-1"); continue; }
      printf("1");
      for (i=0, j=2; i<y; i++, j+=2) printf(" %d %d",j+1,j);
      for (k=n; k>=j; k--) printf(" %d",k);
      puts("");
    } else {
      if (y>x+1) { puts("-1"); continue; }
      printf("%d",n);
      for (i=0, j=n-2; i<x; i++, j-=2) printf(" %d %d",j,j+1);
      if (x==y) {
        for (++j; j>0; j--) printf(" %d",j);
      } else {
        for (k=1; k<=j+1; k++) printf(" %d",k);
      }
      puts("");
    }
  }
  return 0;
}