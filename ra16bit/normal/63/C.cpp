#include <stdio.h>
int aa,b,c,a[11111][11],d[11],i,j,k,l,m,n,e,f;
int main() {
  for (i=0; i<10; i++) for (j=0; j<10; j++) if (i!=j) for (k=0; k<10; k++) if (i!=k && j!=k)
    for (l=0; l<10; l++) if (i!=l && j!=l && k!=l) { a[++m][i]=1; a[m][j]=2; a[m][k]=3; a[m][l]=4; }
  scanf("%d",&n);
  for (k=0; k<n; k++) {
    scanf("%d%d%d",&aa,&b,&c);
    for (j=0; j<10; j++) d[j]=0;
    d[aa%10]=4; aa/=10;
    d[aa%10]=3; aa/=10;
    d[aa%10]=2; aa/=10;
    d[aa%10]=1;
    for (i=1; i<=m; ) {
      for (e=f=j=0; j<10; j++) if (a[i][j]!=0) {
        if (a[i][j]==d[j]) e++; else if (d[j]!=0) f++;
      }
      if (e!=b || f!=c) {
        for (j=0; j<10; j++) a[i][j]=a[m][j];
        m--;
      } else i++;
    }
  }
  if (m==1) {
    for (j=0; j<10; j++) if (a[1][j]==1) printf("%d",j);
    for (j=0; j<10; j++) if (a[1][j]==2) printf("%d",j);
    for (j=0; j<10; j++) if (a[1][j]==3) printf("%d",j);
    for (j=0; j<10; j++) if (a[1][j]==4) printf("%d\n",j);
  } else if (m==0) puts("Incorrect data"); else puts("Need more data");
  return 0;
}