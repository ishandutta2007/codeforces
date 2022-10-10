#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,a[200200],c[200200],u[200200];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=1; i<=n; i++) if (u[i]==0) {
    for (j=i; u[j]==0; j=a[j]) u[j]=i;
    if (u[j]==i) c[m++]=j;
  }
  for (i=0; i<m; i++) if (a[c[i]]==c[i]) {
    printf("%d\n",m-1);
    for (j=0; j<m; j++) if (j!=i) a[c[j]]=c[i];
    for (j=1; j<=n; j++) printf("%d%c",a[j],(j==n)?'\n':' ');
    return 0;
  }
  printf("%d\n",m);
  for (j=0; j<m; j++) a[c[j]]=c[0];
  for (j=1; j<=n; j++) printf("%d%c",a[j],(j==n)?'\n':' ');
  return 0;
}