#include <bits/stdc++.h>
using namespace std;
const int inf=2000000000;
int n,m,i,j,k,a[82][82],c[22],u[82],best=inf;
pair<int,int> b[82][82][82];
void rec(int l, int prv, int dist) {
  if (dist>=best) return;
  if (l==m) {
    dist+=b[prv][0][0].first;
    if (dist>=best) return;
    for (int j=2; j<=m; j+=2) {
      int cur=c[j],prv=c[j-2],k=0;
      for (; u[b[prv][cur][k].second] && k<n; k++);
      if (k>=n) return;
      if (k>0) {
        dist+=b[prv][cur][k].first-b[prv][cur][0].first;
        if (dist>=best) return;
      }
    }
    best=dist;
    return;
  }
  for (int i=0; i<n; i++) {
    c[l]=i;
    u[i]++;
    rec(l+2,i,dist+b[prv][i][0].first);
    u[i]--;
  }
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) for (j=0; j<n; j++) scanf("%d",&a[i][j]);
  for (i=0; i<n; i++) for (j=0; j<n; j++) {
    for (k=0; k<n; k++) b[i][j][k]={(k==i || k==j)?inf:(a[i][k]+a[k][j]),k};
    sort(b[i][j],b[i][j]+n);
  }
  c[0]=c[m]=0;
  u[0]=2;
  rec(2,0,0);
  printf("%d\n",best);
  return 0;
}