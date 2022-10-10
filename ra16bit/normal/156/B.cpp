#include <stdio.h>
int n,m,num,i,c,x[100100],a[100100],b[100100];
bool d[100100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    scanf("%d",&x[i]);
    if (x[i]<0) {
      b[-x[i]]++; c++;
    } else a[x[i]]++;
  }
  for (i=1; i<=n; i++) if (a[i]+c-b[i]==m) { num++; d[i]=true; }
  for (i=1; i<=n; i++) if (x[i]<0) {
    if (num==1 && d[-x[i]]) puts("Lie"); else if (d[-x[i]]) puts("Not defined"); else puts("Truth");
  } else {
    if (num==1 && d[x[i]]) puts("Truth"); else if (d[x[i]]) puts("Not defined"); else puts("Lie");
  }
  return 0;
}