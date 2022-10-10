#include <cstdio>
#include <cstring>
#include <memory.h>
#include <algorithm>
using namespace std;
int x,y,n,m,i,j,p,k,ii,f[27][111][111],a[27][111];
char s[111],t[111];
int main() {
  scanf("%d%d",&x,&y);
  scanf("%s",s); n=strlen(s);
  scanf("%s",t); m=strlen(t);
  memset(f,255,sizeof(f));
  for (i=0; i<m; i++) {
    p=i; k=0;
    for (j=0; j<n; j++) if (t[p]==s[j]) {
	  p++;
	  if (p>=m) { p=0; k++; }
	  f[0][i][p]=k;
	}
  }
  for (ii=1; ii<=25; ii++) 
    for (i=0; i<m; i++) for (j=0; j<m; j++) for (k=0; k<m; k++)
	  if (f[ii-1][i][k]>=0 && f[ii-1][k][j]>=0)
	    f[ii][i][j]=max(f[ii][i][j],f[ii-1][i][k]+f[ii-1][k][j]);
  memset(a,255,sizeof(a));
  a[26][0]=0;
  for (ii=25; ii>=0; ii--) if (x&(1<<ii)) {
    for (i=0; i<m; i++) if (a[ii+1][i]>=0)
	  for (j=0; j<m; j++) if (f[ii][i][j]>=0)
	    a[ii][j]=max(a[ii][j],a[ii+1][i]+f[ii][i][j]);
  } else for (i=0; i<m; i++) a[ii][i]=a[ii+1][i];
  printf("%d\n",max(0,a[0][0]/y));
  return 0;
}