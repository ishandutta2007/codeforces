#include <bits/stdc++.h>
using namespace std;
const int MX=400400;
int n,m,i,ii,j,s,z,cur,r,w,x,y,wdth,a[MX],c[MX],k[MX],ans[MX];
bool cmp(int i, int j) {
  if (c[i]!=c[j]) return c[i]>c[j];
  return i<j;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  for (i=0; i<n; i++) {
    if (i==0 || a[i]!=a[i-1]) c[i]=1; else c[i]=c[i-1]+1;
    if (i==n-1 || a[i]!=a[i+1]) k[m++]=i;
  }
  sort(k,k+m,cmp);
  j=m-1;
  for (i=1; i*i<=n; i++) {
    for (; j>=0 && c[k[j]]<i; j--) s+=c[k[j]];
    z=s/i+j+1;
    if (z<i) continue;
    cur=z*i;
    if (i==1 || cur>r) { r=cur; w=i; }
  }
  wdth=r/w;
  printf("%d\n%d %d\n",r,w,wdth);
  for (x=y=i=0; i<m; i++) {
    z=min(w,c[k[i]]);
    for (j=0; j<z; j++) {
      ans[x*wdth+y]=a[k[i]];
      ++x;
      if (x==w) {
        x=0;
        y=y-w+2;
        if (y<0) y+=wdth;
      } else {
        ++y;
        if (y==wdth) y=0;
      }
      if (x==0 && y==0) break;
    }
    if (x==0 && y==0) break;
  }
  for (i=0; i<w; i++) for (j=0; j<wdth; j++) printf("%d%c",ans[i*wdth+j],(j+1==wdth)?'\n':' ');
  return 0;
}