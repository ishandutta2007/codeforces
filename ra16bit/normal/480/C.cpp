#include <stdio.h>
const int md=1000000007;
int n,m,a,b,i,j,f[5005][5005];
int main() {
  scanf("%d%d%d%d",&m,&a,&b,&n);
  if (a>b) {
    a=m-a+1;
    b=m-b+1;
  }
  for (j=a; j<b; j++) f[0][j]=1;
  for (i=1; i<=n; i++) for (j=1; j<b; j++) {
    f[i][j]=(f[i][j-1]+f[i-1][(j+b-1)/2])%md;
    f[i][j]=(f[i][j]+md-f[i-1][j])%md;
    f[i][j]=(f[i][j]+f[i-1][j-1])%md;
  }
  printf("%d\n",f[n][b-1]);
  return 0;
}