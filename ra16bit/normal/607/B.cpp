#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,k,l,z,a[505],f[505][505];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    f[i][i]=1;
  }
  for (l=1; l<n; l++) for (i=0; i+l<n; i++) {
    j=i+l;
    f[i][j]=1+f[i+1][j];
    if (a[i]==a[i+1]) {
      z=(i+1==j)?0:f[i+2][j];
      f[i][j]=min(f[i][j],1+z);
    }
    for (k=i+2; k<=j; k++) if (a[i]==a[k]) {
      z=(k==j)?0:f[k+1][j];
      f[i][j]=min(f[i][j],f[i+1][k-1]+z);
    }
  }
  printf("%d\n",f[0][n-1]);
  return 0;
}