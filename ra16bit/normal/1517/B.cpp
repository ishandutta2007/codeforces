#include <bits/stdc++.h>
using namespace std;
int it,t,n,m,ii,i,j,cnt,pos,a[105][105],u[105][105],r[105][105];
pair<int,int> k[105*105];
int main() {
  scanf("%d",&t);
  for (it=1; it<=t; it++) {
    scanf("%d%d",&n,&m);
    for (cnt=i=0; i<n; i++) for (j=0; j<m; j++, cnt++) {
      scanf("%d",&a[i][j]);
      k[cnt]={a[i][j],cnt};
      r[i][j]=0;
    }
    sort(k,k+cnt);
    for (ii=0; ii<m; ii++) {
      i=k[ii].second/m;
      j=k[ii].second%m;
      u[i][j]=it;
      r[i][ii]=k[ii].first;
    }
    for (i=0; i<n; i++, puts("")) for (pos=j=0; j<m; j++) if (r[i][j]==0) {
      while (pos<m && u[i][pos]==it) pos++;
      u[i][pos]=it;
      printf("%d ",a[i][pos]);
    } else printf("%d ",r[i][j]);
  }
  return 0;
}