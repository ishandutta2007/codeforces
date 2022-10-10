#include <stdio.h>
int i,j,n,m,k,s,c,f[1010][1010],md=1000000007;
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=1; i<=1000; i++) f[0][i]=1;
  for (i=1; i<=1000; i++) {
    s=c=0;
    for (j=3; j<=1000; j++) {
      s+=f[i-1][j-2];
      if (s>=md) s-=md;
      c+=s;
      if (c>=md) c-=md;
      f[i][j]=c;
    }
  }
  printf("%d\n",int((1LL*f[k][n]*f[k][m])%md));
  return 0;
}