#include <cstdio>
#include <algorithm>
using namespace std;
int a[100][100],s[100][100],c,ii,i,j,n,m,z,x,y,r,q,rc;
int ab(int x) {
  return (x<0)?(-x):x;
}
int main() {
  scanf("%d%d",&m,&n); c=(n+1)/2;  
  for (i=1; i<=n; i++) for (j=1; j<=n; j++) { 
    a[i][j]=j; s[i][j]=s[i][j-1]+ab(i-c)+ab(j-c);;
  }
  for (ii=0; ii<m; ii++) {
    scanf("%d",&z); r=-1;
    for (i=1; i<=n; i++) for (j=1; j+z-1<=n; j++) {
      x=a[i][j+z-1]-a[i][j-1];
      y=s[i][j+z-1]-s[i][j-1];
      if (x==z && (r==-1 || y<rc)) {
        rc=y; r=i; q=j;
      }
    }
    if (r==-1) puts("-1"); else {
      printf("%d %d %d\n",r,q,q+z-1);
      for (i=q; i<=n; i++) a[r][i]-=min(i-q+1,z);
    }
  }
  return 0;
}