#include <cstdio>
#include <vector>
using namespace std;
int n,m,i,j,x,y,t,le,ri,h,a[200200],b[200200],c[200200],d[200200],s[200200],r[200200];
vector<pair<int,int> > g[200200];
int main() {
  scanf("%d",&n);
  for (i=n; i>=1; i--) {
    scanf("%d%d",&a[i],&b[i]);
    a[i]=-a[i];
  }
  scanf("%d",&m);
  for (i=0; i<m; i++) {
    scanf("%d%d",&x,&y);
    g[n-x+1].push_back(make_pair(i,n-y+1));
  }
  for (i=1; i<=n; i++) {
    x=a[i]-b[i];
    if (i>1 && x>a[i-1]) {
      c[++t]=i-1;
      d[t]=x-a[i-1];
      s[t]=s[t-1]+d[t];
    } else {
      while (t>0 && x<=a[c[t]]) t--;
      if (t>0) {
        d[t]=min(d[t],x-a[c[t]]);
        s[t]=s[t-1]+d[t];
      }
    }
    for (j=0; j<g[i].size(); j++) {
      x=g[i][j].second;
      le=0; ri=t;
      while (le<ri) {
        h=(le+ri)/2+1;
        if (c[h]<x) le=h; else ri=h-1;
      }
      r[g[i][j].first]=s[t]-s[ri];
    }
  }
  for (i=0; i<m; i++) printf("%d\n",r[i]);
  return 0;
}