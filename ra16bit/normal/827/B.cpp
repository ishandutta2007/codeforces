#include <bits/stdc++.h>
using namespace std;
int n,k,i,j,r;
int main() {
  scanf("%d%d",&n,&k);
  for (r=i=1; ; i++) {
    r++;
    if (i*k+1>=n) break;
    r++;
    if (i*k+2>=n) break;
  }
  printf("%d\n",r);
  for (j=1; j+k<=i*k && j+k<=n; j++) printf("%d %d\n",j,j+k);
  if (r&1) {
    printf("%d %d\n",j,n-1);
    j++;
  }
  for (; j<n; j++) printf("%d %d\n",j,n);
  return 0;
}