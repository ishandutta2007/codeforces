#include <cstdio>
#include <algorithm>
#include <memory.h>
using namespace std;
int n,i,j,k,f[1000010][2],g[1000010][2];
char s[1000010];
int main() {
  gets(s);
  n=strlen(s);
  reverse(s,s+n);
  memset(f,100,sizeof(f));
  f[0][0]=0;
  for (i=0; i<=n+1; i++) if (s[i]=='1') {
    if (f[i][0]+1<f[i+1][0]) {
      f[i+1][0]=f[i][0]+1;
      g[i+1][0]=2;
    }
    if (f[i][0]+1<f[i+1][1]) {
      f[i+1][1]=f[i][0]+1;
      g[i+1][1]=1;
    }
    if (f[i][1]<f[i+1][1]) {
      f[i+1][1]=f[i][1];
      g[i+1][1]=0+10;
    }
  } else {
    if (f[i][0]<f[i+1][0]) {
      f[i+1][0]=f[i][0];
      g[i+1][0]=0;
    }
    if (f[i][1]+1<f[i+1][1]) {
      f[i+1][1]=f[i][1]+1;
      g[i+1][1]=1+10;
    }
    if (f[i][1]+1<f[i+1][0]) {
      f[i+1][0]=f[i][1]+1;
      g[i+1][0]=2+10;
    }
  }
  printf("%d\n",f[n+1][0]);
  for (i=n+1,j=0; i>0; i--,j=k) {
    if (g[i][j]>=10) {
      k=1; g[i][j]-=10;
    } else k=0;
    if (g[i][j]) printf("%c2^%d\n",g[i][j]==1?'-':'+',i-1);
  }
  return 0;
}