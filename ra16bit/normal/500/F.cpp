#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=4004;
int n,p,q,pr,ii,i,j,k,e,x,y,le,ri,r,c[MX],h[MX],t[MX],f[MX][MX],g[MX][MX];
bool st[MX];
bool cmp(int i, int j) {
  return t[i]<t[j];
}
int main() {
  scanf("%d%d",&n,&p);
  for (i=0; i<n; i++) scanf("%d%d%d",&c[i],&h[i],&t[i]);
  for (i=0; i<n; i++) {
    for (k=j=i; j<n; j++) if (t[j]<t[k]) k=j;
    swap(c[i],c[k]);
    swap(h[i],h[k]);
    swap(t[i],t[k]);
  }
  st[0]=true;
  for (ii=i=0; i<20000; i+=p) {
    for (pr=ii; ii<n && t[ii]<i; ii++);
    st[ii]=true;
    for (e=pr; e<ii; e++) for (j=0; j<MX-2; j++) {
      f[e+1][j]=max(f[e+1][j],(e==pr)?0:f[e][j]);
      if (j+c[e]<MX) f[e+1][j+c[e]]=max(f[e+1][j+c[e]],((e==pr)?0:f[e][j])+h[e]);
    }
    for (e=ii-1; e>=pr; e--) for (j=0; j<MX-2; j++) {
      g[e][j]=max(g[e][j],g[e+1][j]);
      if (j+c[e]<MX) g[e][j+c[e]]=max(g[e][j+c[e]],g[e+1][j]+h[e]);
    }
  }
  scanf("%d",&q);
  while (q--) {
    scanf("%d%d",&x,&y);
    le=upper_bound(t,t+n,x-p)-t;
    ri=upper_bound(t,t+n,x)-t;
    for (r=i=0; i<=y; i++) if (le<ri) {
      e=0;
      if (!st[le] || ri>=n || t[le]/p<t[ri]/p) e+=g[le][i];
      if (!st[ri] || t[le]/p<t[ri-1]/p) e+=f[ri][y-i];
      r=max(r,e);
    }
    printf("%d\n",r);
  }
  return 0;
}