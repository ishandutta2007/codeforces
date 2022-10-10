#include <cstdio>
using namespace std;
int fx[1010][1010],fy[1010][1010],gx[1010][1010],gy[1010][1010],nx=-1,a,b,n,i,j,k;
char r[1010];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) for (j=0; j<n; j++) {
    scanf("%d",&k); a=b=0;
    if (k==0) { nx=i; k=10; }
    while (k%2==0) { a++; k/=2; }
    while (k%5==0) { b++; k/=5; }
    if (i==0) {
      if (j==0) { fx[i][j]=a; fy[i][j]=b; continue; }
      fx[i][j]=fx[i][j-1]+a; gx[i][j]=1;
      fy[i][j]=fy[i][j-1]+b; gy[i][j]=1;
    } else if (j==0) {
      fx[i][j]=fx[i-1][j]+a; gx[i][j]=0;
      fy[i][j]=fy[i-1][j]+b; gy[i][j]=0;
    } else {
      if (fx[i-1][j]<fx[i][j-1]) {
        fx[i][j]=fx[i-1][j]+a; gx[i][j]=0;
      } else {
        fx[i][j]=fx[i][j-1]+a; gx[i][j]=1;
      }
      if (fy[i-1][j]<fy[i][j-1]) {
        fy[i][j]=fy[i-1][j]+b; gy[i][j]=0;
      } else {
        fy[i][j]=fy[i][j-1]+b; gy[i][j]=1;
      }
    }
  }
  if (fx[n-1][n-1]>fy[n-1][n-1]) for (i=0; i<n; i++) for (j=0; j<n; j++) { fx[i][j]=fy[i][j]; gx[i][j]=gy[i][j]; }
  if (fx[n-1][n-1]>0 && nx!=-1) {
    fx[n-1][n-1]=1;
    for (i=0; i<nx; i++) r[i]='D';
    for (i=0; i<n-1; i++) r[nx+i]='R';
    for (i=nx; i<n-1; i++) r[n+i-1]='D';
  } else {
    for (i=j=n-1, k=0; k<(n-1)*2; k++) if (gx[i][j]==0) {
      r[(n-1)*2-k-1]='D'; i--;
    } else {
      r[(n-1)*2-k-1]='R'; j--;
    }
  }
  printf("%d\n",fx[n-1][n-1]);
  puts(r);
  return 0;
}