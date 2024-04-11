#include <bits/stdc++.h>
using namespace std;
int n,m,i,j;
int main() {
  scanf("%d%d",&n,&m);
  if (n==1 && m==1) { puts("0"); return 0; }
  if (n<=m) {
    for (i=0; i<n; i++,puts("")) for (j=0; j<m; j++) printf("%d ",(i+1)*(n+j+1));
  } else {
    for (i=0; i<n; i++,puts("")) for (j=0; j<m; j++) printf("%d ",(m+i+1)*(j+1));
  }
  return 0;
}