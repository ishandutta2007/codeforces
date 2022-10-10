#include <stdio.h>
int n,m,k,i;
double s;
int main() {
  scanf("%d%d%d",&n,&m,&k); k++; s=1.0;
  for (i=0; i<k; i++) s*=double(m-i)/double(n+i+1);
//  if (k+n<m) s=1; else if (k>=m) s=0;
  if (s>1.0) s=1.0;
  printf("%.7f\n",1.0-s);
/*  for (i=0; i<=200000; i++) for (j=0; j<=k; j++) for (z=0; z<=j; z++) v[i][j]+=v[;
  for (i=0; i<=n; i++) {
    j=i+k+1;
    if (j>m) break;
    f[i+j]=0.5*g[i+j-1];
  }*/
  return 0;
}