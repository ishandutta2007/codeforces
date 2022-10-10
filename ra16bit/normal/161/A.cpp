#include <stdio.h>
int n,m,x,y,i,j,r,a[100100],b[100100],ra[100100],rb[100100];
int main() {
  scanf("%d%d%d%d",&n,&m,&x,&y); y+=x;
  for (i=0; i<n; i++) { scanf("%d",&a[i]); a[i]-=x; }
  for (i=0; i<m; i++) scanf("%d",&b[i]);
  for (i=j=0; i<n && j<m; ) if (b[j]>=a[i] && b[j]<=a[i]+y) {
    ra[r]=++i; rb[r++]=++j;
  } else if (b[j]<a[i]) j++; else i++;
  printf("%d\n",r);
  for (i=0; i<r; i++) printf("%d %d\n",ra[i],rb[i]);
  return 0;
}