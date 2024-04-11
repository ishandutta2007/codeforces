#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,x,y,tot,cnt,w,lw,a[22][2],b[22][2],c[22];
set<int> sa[22],sb[22];
bool aw,bw,ad,bd;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) for (j=0; j<2; j++) scanf("%d",&a[i][j]);
  for (i=0; i<m; i++) for (j=0; j<2; j++) scanf("%d",&b[i][j]);
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    for (cnt=x=0; x<2; x++) for (y=0; y<2; y++) if (a[i][x]==b[j][y]) { cnt++; w=a[i][x]; }
    if (cnt!=1) continue;
    if (++c[w]==1) { tot++; lw=w; }
    sa[i].insert(w);
    sb[j].insert(w);
  }
  if (tot!=1) {
    for (i=0; i<n; i++) if (sa[i].size()>=1) {
      aw=true;
      if (sa[i].size()>1) ad=true;
    }
    for (i=0; i<m; i++) if (sb[i].size()>=1) {
      bw=true;
      if (sb[i].size()>1) bd=true;
    }
    if (aw && bw && !ad && !bd) puts("0"); else puts("-1");
  } else printf("%d\n",lw);
  return 0;
}