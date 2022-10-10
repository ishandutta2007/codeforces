#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,k,c,r,a[102][10002],b[102][10002];
char s[10002];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%s",s);
	for (j=0; j<m; j++) if (s[j]=='1') break;
	if (j>=m) { puts("-1"); return 0; }
	b[i][m]=j; k=-1;
	for (j=m-1; j>=0; j--) if (s[j]=='1') {
	  b[i][j]=0;
	  if (k==-1) k=j;
	} else b[i][j]=b[i][j+1]+1;
	a[i][0]=(s[0]=='1')?0:(m-k);
	for (j=1; j<m; j++) if (s[j]=='1') a[i][j]=0; else a[i][j]=a[i][j-1]+1;
  }
  for (j=0; j<m; j++) {
    for (c=i=0; i<n; i++) c+=min(a[i][j],b[i][j]);
	if (j==0 || c<r) r=c;
  }
  printf("%d\n",r);
  return 0;
}