#include <stdio.h>
#include <string.h>
#include <memory.h>
int n,i,m,j;
char s[44],g[20][20];
long long a[20],f[20][20];
int main() {
  gets(s); gets(s); n=strlen(s); m=n/2;
  a[m-1]=1;
  for (i=m-2; i>=0; i--) a[i]=a[i+1]*10;
  memset(f,255,sizeof(f)); f[0][0]=0;
  for (i=0; i<=m; i++) for (j=0; j<=m; j++) if (f[i][j]>=0) {
    if (i<m && f[i][j]+a[i]*(s[i+j]-'0')>f[i+1][j]) {
      f[i+1][j]=f[i][j]+a[i]*(s[i+j]-'0');
      g[i+1][j]='M';
    }
    if (j<m && f[i][j]+a[j]*(s[i+j]-'0')>f[i][j+1]) {
      f[i][j+1]=f[i][j]+a[j]*(s[i+j]-'0');
      g[i][j+1]='H';
    }
  }
  for (i=j=m; i>0 || j>0; g[i][j]=='M'?i--:j--) s[i+j-1]=g[i][j];
  puts(s);
  return 0;
}