#include <bits/stdc++.h>
using namespace std;
int n,x,i,j,ii,jj,k,a[1010][1010];
int main() {
  scanf("%d",&n);
  x=n/4;
  for (ii=0; ii<x; ii++) for (jj=0; jj<x; jj++) {
    for (i=0; i<4; i++) for (j=0; j<4; j++, k++) a[ii*4+i][jj*4+j]=k;
  }
  for (i=0; i<n; i++) for (j=0; j<n; j++) printf("%d%c",a[i][j],(j==n-1)?'\n':' ');
  return 0;
}