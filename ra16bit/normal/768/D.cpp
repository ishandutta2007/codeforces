#include <stdio.h>
int i,ii,i1,j,k,e,q,r[1010];
double f[2][1010],eps=1e-7;
int main() {
  scanf("%d%d",&k,&q);
  f[0][0]=1;
  for (e=i=0; i<10000; i++) {
    ii=i&1; i1=1-ii;
    for (j=0; j<=k; j++) f[i1][j]=0;
    for (j=0; j<=i && j<=k; j++) {
      f[i1][j]+=f[ii][j]*j/k;
      f[i1][j+1]+=f[ii][j]*(k-j)/k;
    }
    for (; e<=1000 && 2000*f[ii][k]>e-eps; e++) r[e]=i;
  }
  while (q--) {
    scanf("%d",&i);
    printf("%d\n",r[i]);
  }
  return 0;
}