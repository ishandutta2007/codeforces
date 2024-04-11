#include <stdio.h>
const int md=1000000007;
int n,i,j,p,f[1010];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&p);
    f[i]=1;
    for (j=p; j<i; j++) f[i]=(f[i]+f[j]+1)%md;
  }
  for (p=0, i=1; i<=n; i++) p=(p+f[i]+1)%md;
  printf("%d\n",p);
  return 0;
}