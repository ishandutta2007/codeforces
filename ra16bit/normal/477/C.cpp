#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,i,j,k,p,f[2020][505],g[2020][2020];
char s[2020],t[505];
int main() {
  gets(s); n=strlen(s);
  gets(t); m=strlen(t);
  memset(f,120,sizeof(f));
  memset(g,120,sizeof(g));
  f[0][0]=g[0][0]=0;
  for (i=1; i<=n; i++) {
    f[i][0]=g[i][0]=0;
    for (j=1; j<=m; j++) {
      f[i][j]=f[i-1][j]+1;
      if (s[i-1]==t[j-1]) f[i][j]=min(f[i][j],f[i-1][j-1]);
    }
    for (j=1; j<=i; j++) {
      g[i][j]=g[i-1][j];
      if (f[i][m]<f[0][1]) g[i][j]=min(g[i][j],g[i-m-f[i][m]][j-1]+f[i][m]);
    }
  }
  for (i=0; i<=n; i++) {
    for (j=(n-i)/m; j>=0; j--) if (g[n][j]<=i) break;
    printf("%d%c",j,i==n?'\n':' ');
  }
  return 0;
}