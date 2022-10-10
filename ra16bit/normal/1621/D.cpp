#include <bits/stdc++.h>
using namespace std;
const int MX=505;
int t,n,mid,i,j,x,y,d,res,c[MX][MX];
long long add;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    mid=n; n*=2;
    for (add=i=0; i<n; i++) for (j=0; j<n; j++) {
      scanf("%d",&c[i][j]);
      if (i>=mid && j>=mid) add+=c[i][j];
    }
    res=min(c[mid][0],c[0][mid]);
    res=min(res,c[0][n-1]);
    res=min(res,c[n-1][0]);
    res=min(res,c[mid-1][n-1]);
    res=min(res,c[n-1][mid-1]);
    res=min(res,c[mid-1][mid]);
    res=min(res,c[mid][mid-1]);
    printf("%lld\n",res+add);
  }
  return 0;
}