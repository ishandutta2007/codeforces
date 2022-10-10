#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int n,m,ii,i,j,nx,cur,ans,le,ri,a[2][MX*2],b[MX*4],k[MX*2],ns[MX*4],nle[MX*4],nri[MX*4],xs[MX*4],xle[MX*4],xri[MX*4];
bool cmp(int i, int j) {
  if (a[cur][i]!=a[cur][j]) return a[cur][i]<a[cur][j];
  return i%2<j%2;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) for (j=0; j<2; j++) {
    scanf("%d%d",&a[j][i*2],&a[j][i*2+1]);
    b[m++]=a[j][i*2];
    b[m++]=a[j][i*2+1];
    k[i*2+j]=i*2+j;
  }
  sort(b,b+m);
  for (j=0; j<2; j++) for (i=0; i<2*n; i++) a[j][i]=lower_bound(b,b+m,a[j][i])-b+1;
  for (cur=0; cur<2; cur++) {
    sort(k,k+2*n,cmp);
    memset(ns,100,sizeof(ns));
    memset(nle,100,sizeof(nle));
    memset(nri,100,sizeof(nri));
    memset(xs,0,sizeof(xs));
    memset(xle,0,sizeof(xle));
    memset(xri,0,sizeof(xri));
    for (ii=0; ii<2*n; ii++) {
      i=k[ii];
      if (i&1) {
        le=a[cur^1][i-1];
        ri=a[cur^1][i];
        ns[ri]=min(ns[ri],le);
        for (j=ri; j<=m; j=(j<<1)-(j&(j-1))) nle[j]=min(nle[j],le);
        for (j=ri; j>0; j&=j-1) nri[j]=min(nri[j],le);
        xs[le]=max(xs[le],ri);
        for (j=le; j<=m; j=(j<<1)-(j&(j-1))) xle[j]=max(xle[j],ri);
        for (j=le; j>0; j&=j-1) xri[j]=max(xri[j],ri);
      } else {
        le=a[cur^1][i];
        ri=a[cur^1][i+1];
        ans=min(ns[le],ns[m]);
        for (j=le; ; j=nx) {
          nx=(j<<1)-(j&(j-1));
          if (nx>m) break;
          ans=min(ans,nri[j]);
        }
        ans=min(ans,ns[j]);
        for (j=m; ; j=nx) {
          nx=(j&(j-1));
          if (nx<le) break;
          ans=min(ans,nle[j]);
        }
        ans=min(ans,ns[j]);
        if (ans<=ri) { puts("NO"); return 0; }
        ans=max(xs[1],xs[ri]);
        for (j=1; ; j=nx) {
          nx=(j<<1)-(j&(j-1));
          if (nx>ri) break;
          ans=max(ans,xri[j]);
        }
        ans=max(ans,xs[j]);
        for (j=ri; ; j=nx) {
          nx=(j&(j-1));
          if (nx<1) break;
          ans=max(ans,xle[j]);
        }
        ans=max(ans,xs[j]);
        if (ans>=le) { puts("NO"); return 0; }
      }
    }
  }
  puts("YES");
  return 0;
}