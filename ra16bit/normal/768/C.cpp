#include <stdio.h>
int n,m,x,i,e,a,cur,c[1111],d[1111];
int main() {
  scanf("%d%d%d",&n,&m,&x);
  for (i=0; i<n; i++) {
    scanf("%d",&a);
    c[a]++;
  }
  for (int ee=0; ee<m; ee++) {
  for (i=0; i<1024; i++) d[i]=0;
  for (cur=i=0; i<1024; i++) if (c[i]>0) {
    if (cur%2==0) {
      e=(c[i]+1)/2;
      d[i^x]+=e;
      d[i]+=c[i]-e;
    } else {
      e=c[i]/2;
      d[i^x]+=e;
      d[i]+=c[i]-e;
    }
    cur+=c[i];
  }
  for (i=0; i<1024; i++) c[i]=d[i];
  }
  for (i=0; i<1024; i++) if (c[i]>0) a=i;
  printf("%d ",a);
  for (i=0; i<1024; i++) if (c[i]>0) break;
  printf("%d\n",i);
  return 0;
}