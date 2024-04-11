#include <bits/stdc++.h>
using namespace std;
const int MX=104,MSK=(1<<14)+5,inf=1100000000;
int n,m,i,j,e,res,ii,jj,msk,nmsk,dstx,xa[17],ya[17],xb[MX],yb[MX],tb[MX],k[MX],dsta[MSK][17],dstb[MSK][MX],btm[MSK][MX],f[MX][MSK],ptr[MSK];
bool cmp(int i, int j) { return tb[i]<tb[j]; }
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d%d",&xa[i],&ya[i]);
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&xb[i],&yb[i],&tb[i]);
    k[i]=i;
  }
  for (i=0; i<(1<<n); i++) {
    for (j=0; j<n; j++) if (((i>>j)&1)==0) {
      dsta[i][j]=inf;
      for (e=0; e<n; e++) if ((i>>e)&1) dsta[i][j]=min(dsta[i][j],abs(xa[e]-xa[j])+abs(ya[e]-ya[j]));
    }
    for (j=0; j<m; j++) {
      dstb[i][j]=inf;
      for (e=0; e<n; e++) if ((i>>e)&1) dstb[i][j]=min(dstb[i][j],abs(xa[e]-xb[j])+abs(ya[e]-yb[j]));
    }
    for (j=0; j<=m; j++) btm[i][j]=inf;
  }
  for (i=0; i<n; i++) btm[(1<<i)][0]=0;
  res=1;
  sort(k,k+m,cmp);
  for (ii=0; ii<m; ii++) {
    i=k[ii];
    f[ii][0]=max(f[ii][0],1);
    for (msk=0; msk<(1<<n); msk++) {
      for (jj=ii-1; jj>=0; jj--) if (f[jj][msk]>0) {
        j=k[jj];
        dstx=abs(xb[i]-xb[j])+abs(yb[i]-yb[j]);
        if (tb[j]+min(dstx,dstb[msk][i])<=tb[i]) f[ii][msk]=max(f[ii][msk],f[jj][msk]+1);
      }
      if (msk>0) for (; ptr[msk]<=m; ptr[msk]++) if (btm[msk][ptr[msk]]<tb[i]) {
        j=ptr[msk];
        for (e=0; e<n; e++) if (((msk>>e)&1)==0) {
          nmsk=(msk|(1<<e));
          btm[nmsk][j]=min(btm[nmsk][j],btm[msk][j]+dsta[msk][e]); // was for
        }
        //if (btm[msk][j]+dstb[msk][i]<=tb[i]) f[ii][msk]=max(f[ii][msk],j+1);
        for (jj=ii; jj<m; jj++) {
          e=k[jj];
          if (btm[msk][j]+dstb[msk][e]<=tb[e]) f[jj][msk]=max(f[jj][msk],j+1);
        }
      } else break;
      if (f[ii][msk]>0) {
        res=max(res,f[ii][msk]);
        if (msk>0) btm[msk][f[ii][msk]]=min(btm[msk][f[ii][msk]],tb[i]);  // was for
        for (j=0; j<n; j++) if (((msk>>j)&1)==0) {
          nmsk=(msk|(1<<j));
          btm[nmsk][f[ii][msk]]=min(btm[nmsk][f[ii][msk]],tb[i]+min(abs(xb[i]-xa[j])+abs(yb[i]-ya[j]),dsta[msk][j]));  //was for
        }
      }
    }
  }
  printf("%d\n",res);
  return 0;
}