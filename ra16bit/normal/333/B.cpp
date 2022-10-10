#include <stdio.h>
int n,m,i,x,y,r;
bool a[1010],b[1010];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    a[x]=true;
    b[y]=true;
  }
  a[1]=a[n]=true;
  b[1]=b[n]=true;
  for (i=1; i<n-i+1; i++) {
    x=n-i+1;
    if (!a[i]) r++;
    if (!b[i]) r++;
    if (!a[x]) r++;
    if (!b[x]) r++;
  }
  if (i==n-i+1 && (a[i]==false || b[i]==false)) r++;
  printf("%d\n",r);
  return 0;
}