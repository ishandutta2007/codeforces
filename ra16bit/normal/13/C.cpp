#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[5050],b[5050],i1,i2,i,j,t;
long long r,e,ee,f[2][5050];
int ab(int x) { return (x<0)?(-x):x; }
int main() {
  scanf("%d",&n); t=a[n]=1000000001;
  for (i=0; i<n; i++) { scanf("%d",&a[i]); b[i]=a[i]; }
  sort(a,a+n);
  for (i=0; i<n; i++) {
    f[0][i]=ab(b[0]-a[i]);
    if (i>0 && f[0][i-1]<f[0][i]) f[0][i]=f[0][i-1];
  }
  for (i=1; i<n; i++) {
    i1=i&1; i2=1-i1;
    for (j=0; j<n; j++) {
      f[i1][j]=f[i2][j]+ab(b[i]-a[j]);
      if (j>0 && f[i1][j-1]<f[i1][j]) f[i1][j]=f[i1][j-1];
    }
  }
  printf("%I64d\n",f[(n-1)&1][n-1]);
  return 0;
}