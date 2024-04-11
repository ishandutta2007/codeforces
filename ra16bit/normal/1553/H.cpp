#include <bits/stdc++.h>
using namespace std;
const int MX=(1<<20);
int n,m,num,i,j,k,cur,a[MX],b[MX*21][2],ans[21][MX];
int lfs(int l, int i, int msk) {
  int cur=((msk>>l)&1);
  if (b[i][cur]) return lfs(l-1,b[i][cur],msk);
  if (b[i][cur^1]) return lfs(l-1,b[i][cur^1],msk)+(1<<l);
  return 0;
}
int rfs(int l, int i, int msk) {
  int cur=((msk>>l)&1);
  if (b[i][cur^1]) return rfs(l-1,b[i][cur^1],msk)+(1<<l);
  if (b[i][cur]) return rfs(l-1,b[i][cur],msk);
  return 0;
}
void dfs(int l, int i) {
  if (b[i][0] && b[i][1]) {
    int msk=0,cur;
    for (; msk<(1<<l); msk++) {
      int ll=lfs(l-1,b[i][1],msk);
      int rr=rfs(l-1,b[i][0],msk);
      ans[l][msk]=min(ans[l][msk],(1<<l)+ll-rr);
    }
    for (; msk<2*(1<<l); msk++) {
      int ll=lfs(l-1,b[i][0],msk);
      int rr=rfs(l-1,b[i][1],msk);
      ans[l][msk]=min(ans[l][msk],(1<<l)+ll-rr);
    }
  }
  if (b[i][0]) dfs(l-1,b[i][0]);
  if (b[i][1]) dfs(l-1,b[i][1]);
}
int main() {
  scanf("%d%d",&n,&m);
  for (num=i=0; i<n; i++) {
    scanf("%d",&a[i]);
    for (j=k=0; j<m; j++) {
      cur=((a[i]>>(m-1-j))&1);
      if (b[k][cur]==0) b[k][cur]=++num;
      k=b[k][cur];
    }
  }
  for (j=0; j<m; j++) for (i=0; i<(1<<(j+1)); i++) ans[j][i]=(1<<m);
  dfs(m-1,0);
  for (j=0; j+1<m; j++) for (i=0; i<(1<<(j+1)); i++)
    for (k=i; k<(1<<m); k+=(1<<(j+1))) ans[m-1][k]=min(ans[m-1][k],ans[j][i]);
  for (i=0; i<(1<<m); i++) printf("%d ",ans[m-1][i]);
  return 0;
}