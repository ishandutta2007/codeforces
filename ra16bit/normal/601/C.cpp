#include <stdio.h>
int n,m,a,i,e,s;
long double p[102][100010],sp[100010],pm,cur,r;
int main() {
  scanf("%d%d",&n,&m);
  if (m==1) { puts("1"); return 0; }
  p[0][0]=1; pm=1./(m-1.);
  for (i=0; i<n; i++) {
    scanf("%d",&a);
    s+=a;
    sp[0]=p[i][0];
    for (e=1; e<=(i+1)*m; e++) {
      sp[e]=p[i][e]+sp[e-1];
      cur=sp[e-1];
      if (e>m) cur-=sp[e-m-1];
      if (e>=a) cur-=p[i][e-a];
      p[i+1][e]=cur*pm;
    }
  }
  for (e=1; e<s; e++) r+=p[n][e]*(m-1.);
  printf("%.16lf\n",double(r)+1.);
  return 0;
}