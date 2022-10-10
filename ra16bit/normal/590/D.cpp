#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MK=75*75+5;
int n,m,s,i,ii,i1,j,k,a,cur,r,f[2][152][MK];
int main() {
  scanf("%d%d%d",&n,&m,&s);
  memset(f,120,sizeof(f));
  r=f[0][0][0];
  f[0][0][0]=0;
  for (i=0; i<n; i++) {
    scanf("%d",&a);
    ii=i&1; i1=1-ii;
    for (j=0; j<m; j++) for (k=0; k<=s && k<MK; k++) f[i1][j][k]=f[ii][j][k];
    for (j=0; j<m; j++) for (k=0; k<=s && k<MK; k++) if (k+i-j<=s && f[ii][j][k]<r) {
      cur=f[ii][j][k]+a;
      if (j+1==m) r=min(r,cur); else f[i1][j+1][k+i-j]=min(f[i1][j+1][k+i-j],cur);
    }
  }
  printf("%d\n",r);
  return 0;
}