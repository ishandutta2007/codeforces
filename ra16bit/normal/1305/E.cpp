#include <bits/stdc++.h>
using namespace std;
const int MX=1000000000;
int n,m,x,i,j,a[5050],f[5050];
int main() {
  scanf("%d%d",&n,&m);
  for (i=3; i<=n; i++) f[i]=f[i-1]+(i-1)/2;
  if (f[n]<m) { puts("-1"); return 0; }
  for (i=3; i<=n; i++) if (f[i]>m) break;
  m-=f[--i];
  for (j=1; j<=i; j++) a[j]=j;
  if (m>0) {
    for (j=1; j<i; j++) {
      x=(i+j-1)/2-j+1;
      if (x==m) {
        a[i+1]=i+j;
        break;
      }
    }
    if (j>=i) { puts("-1~"); return 0; }
    ++i;
  }
  x=a[i]+1;
  for (j=2; j<=i; j++) if (a[j]!=a[j-1]+1) { x=a[j-1]+1; break; }
  for (++i; i<=n; ++i) {
    a[i]=a[i-1]+x;
    if (a[i]>MX) break;
  }
  if (i<=n) { puts("-1#"); return 0; }
  for (i=1; i<=n; i++) printf("%d ",a[i]);
  return 0;
}