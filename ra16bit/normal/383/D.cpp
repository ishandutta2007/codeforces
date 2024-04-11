#include <stdio.h>
const int MX=10010,md=1000000007;
int n,i,j,a,r,f[1002][2*MX];
int main() {
  scanf("%d",&n);
  for (i=0; ; i++) {
    r+=f[i][MX];
    if (r>=md) r-=md;
    if (i==n) break;
    scanf("%d",&a);
    f[i][MX]++;
    if (f[i][MX]>=md) f[i][MX]-=md;
    for (j=0; j<2*MX; j++) if (f[i][j]) {
      f[i+1][j+a]+=f[i][j];
      if (f[i+1][j+a]>=md) f[i+1][j+a]-=md;
      f[i+1][j-a]+=f[i][j];
      if (f[i+1][j-a]>=md) f[i+1][j-a]-=md;
    }
  }
  printf("%d\n",r);
  return 0;
}