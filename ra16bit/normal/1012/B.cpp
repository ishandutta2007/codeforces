#include <bits/stdc++.h>
int n,m,q,i,x,y,r,p[400400],rk[400400];
void un(int a, int b) {
  if (a==b) return; else r--;
  if (rk[a]>rk[b]) p[b]=a; else {
    p[a]=b;
    if (rk[a]==rk[b]) rk[b]++;
  }
}
int fs(int x) {
  if (x!=p[x]) p[x]=fs(p[x]);
  return p[x];
}
int main() {
  scanf("%d%d%d",&n,&m,&q);
  r=n+m;
  for (i=1; i<=r; i++) p[i]=i;
  while (q--) {
    scanf("%d%d",&x,&y);
    un(fs(x),fs(n+y));
  }
  printf("%d\n",r-1);
  return 0;
}