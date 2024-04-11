#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,e,r,tot,a[111][111],b[111],k[111],ri[111];
bool cmp(int i, int j) { return b[i]<b[j]; }
int main() {
  scanf("%d%d",&m,&n); r=n;
  for (i=0; i<n; i++) { ri[i]=i; k[i]=i; }
  for (i=0; i<n; i++) for (j=0; j<m; j++) scanf("%d",&a[i][j]);
  for (e=0; e<m-1; e++) {
    for (tot=i=0; i<n; i++) {
      b[i]=a[i][e]-a[i][m-1];
      tot+=b[i];
    }
    sort(k,k+n,cmp);
    for (i=0; tot<0 && i<n; i++) tot-=b[k[i]];
    if (i<r) {
      r=i;
      for (j=0; j<i; j++) ri[j]=k[j];
    }
  }
  printf("%d\n",r);
  for (i=0; i<r; i++) printf("%d ",ri[i]+1);
  return 0;
}