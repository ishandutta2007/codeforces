#include <stdio.h>
int t,it,i,j,x,y,p,a[22],f[22][11],fj[22][11],fx[22][11],fy[22][11];
long long z,r[7];
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%I64d",&z);
    for (i=0; i<19; i++) { a[i]=z%10; z/=10; }
    f[0][0]=it;
    for (i=0; i<19; i++) for (j=0; j<10; j++) if (f[i][j]==it)
      for (x=0; x<=6; x++) for (y=0; x+y<=6; y++) if ((j+x*4+y*7)%10==a[i]) {
        f[i+1][(j+x*4+y*7)/10]=it;
        fj[i+1][(j+x*4+y*7)/10]=j;
        fx[i+1][(j+x*4+y*7)/10]=x;
        fy[i+1][(j+x*4+y*7)/10]=y;
      }
    if (f[19][0]==it) {
      for (p=0; p<6; p++) r[p]=0;
      for (i=19, j=0; i>0; i--) {
        x=fx[i][j];
        y=fy[i][j];
        for (p=0; p<6; p++) {
          r[p]*=10;
          if (p<x) r[p]+=4; else if (p<x+y) r[p]+=7;
        }        
        j=fj[i][j];
      }
      for (i=0; i<6; i++) printf("%I64d%c",r[i],i==5?'\n':' ');
    } else puts("-1");
  }
  return 0;
}