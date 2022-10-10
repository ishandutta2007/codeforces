#include <bits/stdc++.h>
using namespace std;
const int MX=105;
int n,i,ii,i1,j,k,cur,res,a[MX],b[MX],f[2][MX][MX*MX];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d%d",&a[i],&b[i]);
  f[0][0][0]=1;
  for (cur=i=0; i<n; i++) {
    ii=i&1; i1=1-ii; 
    memset(f[i1],0,sizeof(f[i1]));
    for (j=0; j<=i; j++) for (k=0; k<=cur; k++) if (f[ii][j][k]) {
      f[i1][j][k]=max(f[i1][j][k],f[ii][j][k]+b[i]);
      f[i1][j+1][k+a[i]]=max(f[i1][j+1][k+a[i]],f[ii][j][k]+b[i]*2);
    }
    cur+=a[i];
  }
  ii=n&1;
  for (j=1; j<=n; j++) {
    for (res=k=0; k<=cur; k++) res=max(res,min(k*2,f[ii][j][k]-1));
    printf("%.10lf ",res*0.5);
  }
  return 0;
}