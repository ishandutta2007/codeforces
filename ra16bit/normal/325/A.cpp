#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,j,k,xa[7],xb[7],ya[7],yb[7];
vector<int> x,y;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%d%d",&xa[i],&ya[i],&xb[i],&yb[i]);
    x.push_back(xa[i]); x.push_back(xb[i]);
    y.push_back(ya[i]); y.push_back(yb[i]);
  }
  sort(x.begin(),x.end());
  x.resize(unique(x.begin(),x.end())-x.begin());
  sort(y.begin(),y.end());
  y.resize(unique(y.begin(),y.end())-y.begin());
  if (x.back()-x[0]!=y.back()-y[0]) { puts("NO"); return 0; }
  for (i=1; i<x.size(); i++) for (j=1; j<y.size(); j++) {
    for (k=0; k<n; k++) if (xa[k]<=x[i-1] && xb[k]>=x[i] && ya[k]<=y[j-1] && yb[k]>=y[j]) break;
    if (k>=n) { puts("NO"); return 0; }
  }
  puts("YES");
  return 0;
}