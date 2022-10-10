#include <stdio.h>
int i,n,m,a[2020];
int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  scanf("%d%d",&n,&m); m--;
  for (i=0; i<n; i++) { scanf("%d",&a[i]); a[n+i]=a[i]; }
  for (i=m; a[i]==0; i++);
  printf("%d\n",(i>=n?i-n:i)+1);
  return 0;
}