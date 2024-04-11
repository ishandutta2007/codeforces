#include <stdio.h>
int n,m,i,z,e,s,x,y,p[5000500],r[5000500];
int findset(int x) {
  if (p[x]!=x) p[x]=findset(p[x]);
  return p[x];
}
void un(int x, int y) {
  if (r[x]<r[y]) p[x]=y; else {
    p[y]=x;
    if (r[x]==r[y]) r[x]++;
  }
}
int main() {
  scanf("%d%d",&n,&m);
  z=n+m+m-2; e=(n+m-1)*2;
  for (i=0; i<e; i++) p[i]=i;
  for (i=0; i<n; i++) {
    x=findset(i);
    y=findset(z+i);
    if (x!=y) un(x,y);
    x=findset(i+m-1);
    y=findset(z+i-m+1);
    if (x!=y) un(x,y);
  }
  for (i=0; i<m; i++) {
    x=findset(i);
    y=findset(z-i);
    if (x!=y) un(x,y);
    x=findset(i+n-1);
    y=findset(z+n-1-i);
    if (x!=y) un(x,y);
  }
  for (i=0; i<e; i++) if (i==findset(i)) s++;
  printf("%d\n",s);
  return 0;
}