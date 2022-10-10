#include <stdio.h>
int n,m,i,j,ii,i1,pp,t;
double f[2][5005],qt,p,q,cur,last,r;
int main() {
  scanf("%d%d",&n,&m);
  f[0][0]=1;
  for (i=0; i<n; i++) {
    scanf("%d%d",&pp,&t);
    ii=i&1; i1=1-ii;
    p=pp/100.; q=1.-p;
    for (qt=j=1; j<=t; j++) qt*=q;
    f[i1][0]=0;
    for (cur=0, j=1; j<=m; j++) {
      if (j-1<=m) cur+=f[ii][j-1];
      f[i1][j]=cur*p;
      cur*=q;
      if (j>=t) {
        last=f[ii][j-t]*qt;
        f[i1][j]+=last;
        cur-=last;
      }
      r+=f[i1][j];
    }
  }
  printf("%.11lf\n",r);
  return 0;
}