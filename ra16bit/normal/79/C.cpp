#include <stdio.h>
#include <string.h>
int n,m,i,j,k,r,a[16],f[100100];
char s[100100],t[16][16];
int main() {
  scanf("%s",s); n=strlen(s);
  scanf("%d",&m);
  for (j=0; j<m; j++) { scanf("%s",t[j]); a[j]=strlen(t[j]); }
  for (i=r=0; i<n; i++) {
    if (i) f[i]=f[i-1]+1; else f[i]=1;
    for (j=0; j<m; j++) if (a[j]<=i+1) {
      for (k=0; k<a[j]; k++) if (s[i-k]!=t[j][a[j]-1-k]) break;
      if (k>=a[j] && a[j]-1<f[i]) f[i]=a[j]-1;
    }
    if (f[i]>f[r]) r=i;
  }
  printf("%d %d\n",f[r],(f[r]==0)?0:(r-f[r]+1));
  return 0;
}