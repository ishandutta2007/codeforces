#include <stdio.h>
int n,k,i,j,a,r;
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d%d",&n,&k);
  for (i=0; i<n; i++) {
    scanf("%d",&a);
    for (j=0; j<3; j++) if (a>=k) a-=k;
    r+=a;
  }
  printf("%d\n",r);
  return 0;
}