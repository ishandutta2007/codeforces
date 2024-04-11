
#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,k,a[100100],b[100100],c[100100][2],f[100100][2],res;
int main() {
  scanf("%d%d%*d%*d",&n,&m); res=n;
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<m; i++) scanf("%d",&b[i]);
  if (m==0) { printf("%d\n",n); return 0; }
  for (i=j=0; i<n; i++) {
    while (j<m && abs(b[j+1]-a[i])<abs(b[j]-a[i])) j++;
    c[i][0]=j;
    if (j<m && abs(b[j+1]-a[i])==abs(b[j]-a[i])) c[i][1]=++j; else c[i][1]=-1;
  }
  for (i=j=0; j<2; j++) f[i][j]=int(c[i][j]>=0);
  for (i=1; i<n; i++) for (j=0; j<2; j++) {
    f[i][j]=max(f[i-1][0],f[i-1][1]);
    if (c[i][j]>=0) for (k=0; k<2; k++) if (c[i-1][k]!=-1) 
     if (c[i][j]!=c[i-1][k] || (c[i][j]==c[i-1][k] && abs(a[i]-b[c[i][j]])==abs(a[i-1]-b[c[i][j]]))) f[i][j]=max(f[i][j],f[i-1][k]+1);
  }
  if (c[n-1][1]==-1) f[n-1][1]=f[n-1][0];
  printf("%d\n",res-max(f[n-1][0],f[n-1][1]));
  return 0;
}