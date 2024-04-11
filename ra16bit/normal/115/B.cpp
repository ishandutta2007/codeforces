#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;
int i,j,n,m,r,f[155][155];
bool q,b[155][155];
char s[155];
int main() {
  scanf("%d%d",&n,&m);
  memset(f,100,sizeof(f));
  f[0][0]=-1; b[0][0]=true;
  for (i=1; i<=n; i++) {
    scanf("%s",s); q=true;
    if ((i&1)==0) {
      for (j=m-1; j>=0; j--) {
        if (j+1<m) f[i][j]=min(f[i][j],f[i][j+1]+1);
        if (q && b[i-1][j]) f[i][j]=min(f[i][j],f[i-1][j]+1);
        if (s[j]=='W') { r=f[i][j]; q=false; }
      }
      for (j=0; j<m; j++) {
        b[i][j]=true;
        if (s[j]=='W') break;
      }
    } else {
      for (j=0; j<m; j++) {
        if (j>0) f[i][j]=min(f[i][j],f[i][j-1]+1);
        if (q && b[i-1][j]) f[i][j]=min(f[i][j],f[i-1][j]+1);
        if (s[j]=='W') { q=false; r=f[i][j]; }
      }
      for (j=m-1; j>=0; j--) {
        b[i][j]=true;
        if (s[j]=='W') break;
      }
    }
  }
  printf("%d\n",r);
  return 0;
}