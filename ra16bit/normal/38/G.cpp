#include <stdio.h>
const int cc=100,cb=200000/cc,ee=5,rb=(ee-1)*cc;
int n,i,j,k,ii,x,y,nb=rb,m,mm,a[cb][cc*ee],p[cb][cc*ee],aa[cb][cc+ee],pp[cb][cc+ee],ss[cb],s[cb],z[cb];
int main() {
  scanf("%d",&n);
  for (ii=0; ii<n; ii++) {
    if (ii==nb) {
      ss[0]=0;
      for (i=mm=0; i<=m; i++) for (j=0; j<s[i]; j++) {
        if (ss[mm]==cc) ss[++mm]=0;
        aa[mm][ss[mm]]=a[i][j];
        pp[mm][ss[mm]++]=p[i][j];
      }
      m=mm;
      for (i=0; i<=m; i++) {
        s[i]=ss[i]; z[i]=0;
        for (j=0; j<s[i]; j++) {
          a[i][j]=aa[i][j]; p[i][j]=pp[i][j];
          if (a[i][j]>z[i]) z[i]=a[i][j];
        }
      }
      nb+=rb;
    }
    scanf("%d%d",&x,&y);
    if (y>ii) y=ii;
    for (i=m; i>=0; i--) if (y<=s[i] || x<z[i]) {
      k=s[i]-y-1;
      for (j=k+1; j<s[i]; j++) if (a[i][j]>x) k=j;
      s[i]++; k++;
      for (j=s[i]-1; j>k; j--) { a[i][j]=a[i][j-1]; p[i][j]=p[i][j-1]; }
      a[i][k]=x; p[i][k]=ii+1;
      if (x>z[i]) z[i]=x;
      break;
    } else y-=s[i];
  }
  for (i=0; i<=m; i++) for (j=0; j<s[i]; j++) printf("%d ",p[i][j]);
  return 0;
}