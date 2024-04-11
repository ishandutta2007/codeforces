#include <bits/stdc++.h>
using namespace std;
const int inf=100000000;
int t,n,m,i,j,k,cur,r,x[111],y[111],g[111][111];
int dist(int i, int j) {
  return abs(x[i]-x[j])+abs(y[i]-y[j]);
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (i=0; i<n; i++) {
      scanf("%d%d",&x[i],&y[i]);
      for (j=0; j<n; j++) g[i][j]=inf*int(i!=j);
    }
    for (i=0; i<n; i++) for (j=0; j<i; j++) if (dist(i,j)<=m) g[i][j]=g[j][i]=1;
    r=inf;
    for (i=0; i<n; i++) {
      for (cur=j=0; j<n; j++) cur=max(cur,g[i][j]);
      r=min(r,cur);
    }
    printf("%d\n",(r>=inf)?-1:r);
  }
  return 0;
}