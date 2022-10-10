#include <stdio.h>
const int md=1000000007;
int n,i,j,a,s,c[1010][1010];
long long r=1;
int main() {
  scanf("%d",&n);
  for (i=0; i<1010; i++) {
    c[i][0]=1;
    for (j=1; j<=i; j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;
  }
  for (i=1; i<=n; i++) {
    scanf("%d",&a); s+=a;
    r=(r*c[s-1][a-1])%md;
  }
  printf("%d\n",int(r));
  return 0;
}