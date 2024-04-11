#include <bits/stdc++.h>
using namespace std;
int n,i,j,x,a,f[111][3];
int main() {
  scanf("%d",&n);
  for (i=0; i<=n; i++) for (j=0; j<3; j++) f[i][j]=n;
  f[0][0]=0;
  for (i=1; i<=n; i++) {
    scanf("%d",&a);
    for (j=0; j<3; j++) {
      f[i][0]=min(f[i][0],f[i-1][j]+1);
      for (x=1; x<3; x++) if ((a&x) && j!=x) f[i][x]=min(f[i][x],f[i-1][j]);
    }
  }
  printf("%d\n",min(f[n][0],min(f[n][1],f[n][2])));
  return 0;
}