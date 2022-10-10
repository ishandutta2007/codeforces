#include <bits/stdc++.h>
using namespace std;
int n,i,j,r,ra[1500500],rb[1500500],p[300300];
void sw(int i, int j) {
  ra[r]=i;
  rb[r++]=j;
  swap(p[i],p[j]);
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&p[i]);
  for (i=1; i<=n; i++) while (p[i]!=i) {
    j=p[i];
    if (2*(j-i)>=n) {
      sw(i,j);
    } else if (2*(i-1)>=n) {
      sw(1,i);
      sw(1,j);
      sw(1,i);
    } else if (2*(n-j)>=n) {
      sw(n,i);
      sw(n,j);
      sw(n,i);
    } else {
      sw(n,i);
      sw(1,j);
      sw(n,1);
      sw(1,j);
      sw(n,i);
    }
  }
  printf("%d\n",r);
  for (i=0; i<r; i++) printf("%d %d\n",ra[i],rb[i]);
  return 0;
}