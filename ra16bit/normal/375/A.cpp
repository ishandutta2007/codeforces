#include <stdio.h>
int i,j,k,l,ii,jj,kk,ll,p,r[11],a[11],cur;
char s[1000100];
int main() {
  scanf("%s",s);
  for (i=0; s[i]; i++) a[s[i]-'0']++;
  a[1]--; a[6]--; a[8]--; a[9]--;
  for (i=1; i<10; i++) if (a[i]>0) {
    for (j=9; j>=0; j--) for (k=0; k<a[j]; k++) { cur=(cur*10+j)%7; printf("%d",j); }
    for (i=1, ii=0; i<=1000; i*=10, ii++)
      for (j=1, jj=0; j<=1000; j*=10, jj++) if (i!=j)
        for (k=1, kk=0; k<=1000; k*=10, kk++) if (i!=k && j!=k)
          for (l=1, ll=0; l<=1000; l*=10, ll++) if (i!=l && j!=l && k!=l && (cur*10000+i*9+j*6+k*8+l)%7==0) {
            r[ii]=9; r[jj]=6; r[kk]=8; r[ll]=1;
            for (p=3; p>=0; p--) printf("%d",r[p]);
            return 0;
          }
  }
  for (i=1, ii=0; i<=1000; i*=10, ii++)
    for (j=1, jj=0; j<=1000; j*=10, jj++) if (i!=j)
      for (k=1, kk=0; k<=1000; k*=10, kk++)
      if (i!=k && j!=k)
        for (l=1, ll=0; l<=1000; l*=10, ll++) 
        if (i!=l && j!=l && k!=l && (i*9+j*6+k*8+l)%7==0) {
          r[ii]=9; r[jj]=6; r[kk]=8; r[ll]=1;
          for (p=3; p>=0; p--) printf("%d",r[p]);
          for (p=0; p<a[0]; p++) printf("0");
          return 0;
        }
  return 0;
}