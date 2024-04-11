#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,r,a[1010][1010],fa[1010][1010],fb[1010][1010],ga[1010][1010],gb[1010][1010];
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) {
    for (j=1; j<=m; j++) {
      scanf("%d",&a[i][j]);
      fa[i][j]=max(fa[i-1][j],fa[i][j-1])+a[i][j];
    }
    for (j=m; j>=1; j--) gb[i][j]=max(gb[i-1][j],gb[i][j+1])+a[i][j];
  }
  for (i=n; i>0; i--) {
    for (j=1; j<=m; j++) ga[i][j]=max(ga[i+1][j],ga[i][j-1])+a[i][j];
    for (j=m; j>=1; j--) fb[i][j]=max(fb[i+1][j],fb[i][j+1])+a[i][j];
  }
  for (i=2; i<n; i++) for (j=2; j<m; j++) {
    r=max(r,fa[i-1][j]+fb[i+1][j]+ga[i][j-1]+gb[i][j+1]);
    r=max(r,fa[i][j-1]+fb[i][j+1]+ga[i+1][j]+gb[i-1][j]);
  }
  printf("%d\n",r);
  return 0;
}