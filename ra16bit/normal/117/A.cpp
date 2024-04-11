#include <stdio.h>
int n,m,t,x,y,z,i,cur;
int main() {
  scanf("%d%d",&n,&m);
  t=2*m-2;
  for (i=0; i<n; i++) {
    scanf("%d%d%d",&x,&y,&z);
    if (x==y) { printf("%d\n",z); continue; }
    cur=z/t;
    if (z<=cur*t+x-1) z=cur*t+x-1;
     else if (z<=cur*t+t-x+1) z=cur*t+t-x+1; else z=(cur+1)*t+x-1;
    cur=z/t; x=y;
    if (z<=cur*t+x-1) z=cur*t+x-1;
     else if (z<=cur*t+t-x+1) z=cur*t+t-x+1; else z=(cur+1)*t+x-1;
    printf("%d\n",z);
  }
  return 0;
}