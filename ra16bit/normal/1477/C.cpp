#include <bits/stdc++.h>
using namespace std;
int n,i,j,it,a[5050],b[5050],x[5050],y[5050],u[5050];
long long scp(int i, int j, int k) {
  long long xa=x[i]-x[j];
  long long ya=y[i]-y[j];
  long long xb=x[k]-x[j];
  long long yb=y[k]-y[j];
  return xa*xb+ya*yb;
}
bool rec(int l, int st) {
  if (l<st) {
    if (l>0 && l+1<=i && scp(b[l-1],b[l],b[l+1])<=0) return false;
    if (l>=0 && l+2<=i && scp(b[l],b[l+1],b[l+2])<=0) return false;
    return true;
  }
  for (int j=i; j>=st; j--) {
    b[l]=a[j];
    if (u[b[l]]==it) continue;
    if (l+2<=i && scp(b[l],b[l+1],b[l+2])<=0) continue;
    u[b[l]]=it;
    if (rec(l-1,st)) {
      a[l]=b[l];
      return true;
    }
    u[b[l]]=-1;
  }
  return false;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d%d",&x[i],&y[i]);
  for (i=0; i<n; i++) {
    a[i]=i;
    for (j=0; j<7 && i-j>=0; j++) {
      ++it;
      if (rec(i,i-j)) break;
    }
    if (j>=7 || i-j<0) { puts("-1"); return 0; }
  }
  for (i=0; i<n; i++) printf("%d ",a[i]+1);
  return 0;
}