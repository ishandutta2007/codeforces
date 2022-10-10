#include <bits/stdc++.h>
using namespace std;
const int MX=1000010;
int n,m,t,ii,i,j,w,now,cur,r,z,e[2020*2020],x[2020][2020],y[2020][2020],cnt[2020],pos[2020],k[2020],xa[2020],ya[2020],xb[2020],yb[2020],xs[2020],ys[2020],c[MX];
bool cmp(int i, int j) {
  if (xb[i]!=xb[j]) return xb[i]<xb[j];
  return yb[i]>yb[j];
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d%d",&xa[i],&ya[i]);
  for (i=0; i<m; i++) {
    scanf("%d%d",&xb[i],&yb[i]);
    k[i]=i;
  }
  sort(k,k+m,cmp);
  for (ii=0; ii<m; ii++) {
    i=k[ii];
    while (t>0 && ys[t]<=yb[i]) t--;
    xs[++t]=xb[i];
    ys[t]=yb[i];
  }
  for (i=0; i<n; i++) for (j=1; j<=t; j++) if (xs[j]>=xa[i] && ys[j]>=ya[i]) {
    x[i][cnt[i]]=xs[j]-xa[i];
    y[i][cnt[i]]=ys[j]-ya[i]+1;
    e[z++]=(x[i][cnt[i]]<<11)+i;
    if (cnt[i]==0) {
      ++c[y[i][cnt[i]]];
      cur=max(cur,y[i][cnt[i]]);
    }
    ++cnt[i];
  }
  if (z==0) { puts("0"); return 0; }
  r=cur;
  sort(e,e+z);
  for (i=0; i<z; i=j) {
    now=(e[i]>>11);
    for (j=i; j<z && (e[j]>>11)==now; j++) {
      w=(e[j]&2047);
      --c[y[w][pos[w]]];
      ++pos[w];
      if (pos[w]<cnt[w]) ++c[y[w][pos[w]]];
      while (cur>0 && c[cur]==0) cur--;
    }
    r=min(r,now+1+cur);
    //printf("%d %d\n",now,cur);
  }
  printf("%d\n",r);
  return 0;
}