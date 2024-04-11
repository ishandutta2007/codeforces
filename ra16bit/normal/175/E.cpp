#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int n1,n2,n3,r1,r2,r3,d1,d2,m,b[22];
double f[22][22][22],c1[22],c2[22],res,a1,a2,a3,z1,z2;
void rec(int l, int s) {
  if (l>m) {
    int j1,j2,k1,k2,i,j;
    for (i=1; i<=m; i++) {
      c1[i]=2*a1;
      c2[i]=2*a2;
      for (j=1; j<=m; j++) {
        z1=max(i-a1,j-a3);
        z2=min(i+a1,j+a3);
        if (z1<z2) c1[i]+=(z2-z1)*(2-b[j]);
        z1=max(i-a2,j-a3);
        z2=min(i+a2,j+a3);
        if (z1<z2) c2[i]+=(z2-z1)*(2-b[j]);
      }
      c1[i]*=d1;
      c2[i]*=d2;
    }
    //for (i=1; i<=m; i++) printf("%d: %d %.2lf %.2lf\n",i,b[i],c1[i],c2[i]);
    for (i=0; i<=m; i++) for (j1=0; j1<=n1; j1++) for (j2=0; j2<=n2; j2++) f[i][j1][j2]=-1e10;
    f[0][0][0]=0;
    for (i=1; i<=m; i++) {
      for (j1=0; j1<=n1; j1++) for (j2=0; j2<=n2; j2++) if (f[i-1][j1][j2]>-1)
        for (k1=0; j1+k1<=n1 && k1<=b[i]; k1++) for (k2=0; j2+k2<=n2 && k1+k2<=b[i]; k2++) {
          f[i][j1+k1][j2+k2]=max(f[i][j1+k1][j2+k2],f[i-1][j1][j2]+c1[i]*k1+c2[i]*k2);
          res=max(res,f[i][j1+k1][j2+k2]);
        }
    }
    return;
  }
  for (int i=0; i<3 && s+i<=n3; i++) if ((m-l)*2>=n3-s-i) {
    b[l]=2-i;
    rec(l+1,s+i);
  }
}
int main() {
  scanf("%d%d%d%d%d%d%d%d",&n1,&n2,&n3,&r1,&r2,&r3,&d1,&d2);
  a1=sqrt(r1*r1-1);
  a2=sqrt(r2*r2-1);
  a3=sqrt(r3*r3-1);
  m=(n1+n2+n3)/2+1;
  rec(1,0);
  printf("%.10lf\n",res);
  return 0;
}