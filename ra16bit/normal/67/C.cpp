#include <cstdio>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;
int ti,td,tr,te,n,m,i,j,x,y,a[4020][28],b[4020][28],f[4020][4020];
char s[4020],t[4020];
int main() {
  scanf("%d%d%d%d",&ti,&td,&tr,&te);
  scanf("%s",s); n=strlen(s);
  scanf("%s",t); m=strlen(t);
  for (j=0; j<26; j++) a[n][j]=b[m][j]=1000000;
  for (i=n-1; i>=0; i--) {
    for (j=0; j<26; j++) a[i][j]=a[i+1][j];
    a[i][s[i]-'a']=i;
  }
  for (i=m-1; i>=0; i--) {
    for (j=0; j<26; j++) b[i][j]=b[i+1][j];
    b[i][t[i]-'a']=i;
  }
  memset(f,120,sizeof(f)); f[0][0]=0;
  for (i=0; i<=n; i++) for (j=0; j<=m; j++) {
    if (i<n && j<m) {
      if (s[i]!=t[j]) {
        f[i+1][j+1]=min(f[i+1][j+1],f[i][j]+tr);
        x=a[i][t[j]-'a'];
        y=b[j][s[i]-'a'];
        if (x<1000000 && y<1000000) f[x+1][y+1]=min(f[x+1][y+1],f[i][j]+te+(x-i-1)*td+(y-j-1)*ti);
      } else f[i+1][j+1]=min(f[i+1][j+1],f[i][j]);
    }
    if (i<n) f[i+1][j]=min(f[i+1][j],f[i][j]+td);
    if (j<m) f[i][j+1]=min(f[i][j+1],f[i][j]+ti);
  }
  printf("%d\n",f[n][m]);
  return 0;
}