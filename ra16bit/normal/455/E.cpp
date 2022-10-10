#include <cstdio>
#include <vector>
using namespace std;
const int MX=100100;
int n,m,i,j,le,ri,h,x,y,t,cst,ct[MX],st[MX],a[MX],s[MX],c[MX],r[MX];
vector<pair<int,int> > g[MX];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    s[i]=s[i-1]+a[i];
  }
  scanf("%d",&m);
  for (i=1; i<=m; i++) {
    scanf("%d%d",&x,&y);
    g[y].push_back(make_pair(x,i));
  }
  for (i=1; i<=n; i++) {
    while (t>0 && a[st[t]]>=a[i]) {
      if (ct[cst]==t) cst--;
      t--;
    }
    st[++t]=i;
    while (cst>0) {
      j=st[ct[cst]];
      c[t]=(s[i]-s[j]+(j-i)*a[j]+a[i]-a[j]-1)/(a[i]-a[j])-i;
      if (c[ct[cst]]<=c[t]) cst--; else break;
    }
    if (cst==0) c[t]=2100000000;
    ct[++cst]=t;
    for (j=0; j<g[i].size(); j++) {
      x=g[i][j].first;
      le=1; ri=cst;
      while (le<ri) {
        h=(le+ri)/2+1;
        if (c[ct[h]]>x-i) le=h; else ri=h-1;
      }
      y=st[ct[ri]];
      r[g[i][j].second]=s[i]-s[y]+(x-i+y)*a[y];
    }
  }
  for (i=1; i<=m; i++) printf("%d\n",r[i]);
  return 0;
}