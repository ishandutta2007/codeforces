#include <stdio.h>
int n,m,i,j,a[5005],b[5005],r;
char s[5005][5005];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (j=0; j<m; j++) {
    for (i=0; i<=m; i++) a[i]=0;
    for (i=0; i<n; i++) {
      if (s[i][j]=='0') b[i]=0; else b[i]++;
      a[b[i]]++;
    }
    for (i=m; i>=0; i--) {
      a[i]+=a[i+1];
      if (a[i]*i>r) r=a[i]*i;
    }
  }
  printf("%d\n",r);
  return 0;
}