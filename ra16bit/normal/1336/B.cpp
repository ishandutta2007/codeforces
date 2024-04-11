#include <bits/stdc++.h>
using namespace std;
int t,i,j,n[3],b[3],a[3][100100];
long long res;
bool u[3];
long long sqr(long long x) { return x*x; }
void rec(int l) {
  if (l>=3) {
    int ii=b[0],jj=b[1],kk=b[2],i=0,j=0,k=0;
    for (i=0; i<n[ii]; i++) {
      for (; j<n[jj] && a[ii][i]>a[jj][j]; j++);
      if (j>=n[jj]) break;
      long long cur=sqr(a[ii][i]-a[jj][j]);
      long long p=cur+sqr(a[kk][k]-a[jj][j])+sqr(a[ii][i]-a[kk][k]);
      res=min(res,p);
      for (k++; k<n[kk]; k++) {
        long long v=cur+sqr(a[kk][k]-a[jj][j])+sqr(a[ii][i]-a[kk][k]);
        if (v>p) break;
        res=min(res,v);
        p=v;
      }
      k--;
    }
    return;
  }
  for (int i=0; i<3; i++) if (!u[i]) {
    u[i]=true;
    b[l]=i;
    rec(l+1);
    u[i]=false;
  }
}
int main() {
  scanf("%d",&t);
  while (t--) {
    for (i=0; i<3; i++) scanf("%d",&n[i]);
    for (i=0; i<3; i++) {
      for (j=0; j<n[i]; j++) scanf("%d",&a[i][j]);
      sort(a[i],a[i]+n[i]);
    }
    res=sqr(a[0][0]-a[1][0])+sqr(a[1][0]-a[2][0])+sqr(a[2][0]-a[0][0]);
    rec(0);
    printf("%I64d\n",res);
  }
  return 0;
}