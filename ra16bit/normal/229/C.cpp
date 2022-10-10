#include <stdio.h>
int n,m,i,x,y,v[1000100];
long long r,c;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
	v[x-1]++;
	v[y-1]++;
  }
  for (i=0; i<n; i++) r+=v[i]*(n-v[i]-1LL);
  c=n*(n-1LL)*(n-2LL);
  printf("%I64d\n",c/6-r/2);
  return 0;
}