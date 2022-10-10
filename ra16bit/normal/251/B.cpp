#include <stdio.h>
int n,k,x,y,i,a[111],p[111],r[111],t[111];
int main() {
  scanf("%d%d",&n,&k);
  for (i=1; i<=n; i++) scanf("%d",&p[i]);
  for (i=1; i<=n; i++) { scanf("%d",&r[i]); a[i]=i; }
  for (x=0; x<=k; x++) {
    for (i=1; i<=n; i++) if (a[i]!=r[i]) break;
    if (i>n) break;
    for (i=1; i<=n; i++) t[i]=a[p[i]];
    for (i=1; i<=n; i++) a[i]=t[i];
  }
  for (i=1; i<=n; i++) a[i]=i;
  for (y=0; y<=k; y++) {
    for (i=1; i<=n; i++) if (a[i]!=r[i]) break;
    if (i>n) break;
    for (i=1; i<=n; i++) t[p[i]]=a[i];
    for (i=1; i<=n; i++) a[i]=t[i];
  }
  if (x==k || y==k) { puts("YES"); return 0; }
  if (x<k && (x&1)==(k&1) && x+y>2) { puts("YES"); return 0; }
  if (y<k && (y&1)==(k&1) && x+y>2) { puts("YES"); return 0; }
  puts("NO");
  return 0;
}