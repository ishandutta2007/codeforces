#include <bits/stdc++.h>
using namespace std;
int n,i,j,k,a,inf,f[111][111][2];
int main() {
  scanf("%d",&n);
  memset(f,100,sizeof(f));
  inf=f[0][0][0];
  f[0][0][0]=0;
  f[0][0][1]=0;
  for (i=0; i<n; i++) {
    scanf("%d",&a);
    for (j=0; j<=i; j++) for (k=0; k<2; k++) if (f[i][j][k]<inf) {
      if (a==0 || a%2==0) f[i+1][j+1][0]=min(f[i+1][j+1][0],f[i][j][k]+int(k==1));
      if (a==0 || a%2==1) f[i+1][j][1]=min(f[i+1][j][1],f[i][j][k]+int(k==0));
    }
  }
  printf("%d\n",min(f[n][n/2][0],f[n][n/2][1]));
  return 0;
}