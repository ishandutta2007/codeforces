#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int n,i,j,k,a[303][303],f[303][303];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) for (j=0; j<n; j++) scanf("%d",&a[i][j]);
  memset(f,140,sizeof(f));
  f[0][0]=a[0][0];
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) for (k=0; k<n; k++) if (j<n-1 && f[j][k]>f[n][n]) f[j+1][k]=max(f[j+1][k],f[j][k]+((j+1!=k)?a[i][j+1]:0));
    for (j=0; j<n; j++) for (k=0; k<n; k++) if (k<n-1 && f[j][k]>f[n][n]) f[j][k+1]=max(f[j][k+1],f[j][k]+((k>=j)?a[i][k+1]:0));
	if (i<n-1) for (j=0; j<n; j++) {
	  for (k=0; k<j; k++) f[j][k]=f[n][n];
	  for (k=j; k<n; k++) f[j][k]+=a[i+1][j]+((j==k)?0:a[i+1][k]);
	}
  }
  printf("%d\n",f[n-1][n-1]);
  return 0;
}