#include <bits/stdc++.h>
using namespace std;
int t,n,z,lst,i,j;
bool check(int r) {
  int j=2;
  for (; j*j<=r; j++) if (r%j==0) break;
  return (j*j>r);
}
int fndnxt(int st) {
  int r=st;
  while (true) {
    if (check(r) && !check(r-st+1)) break;
    r++;
  }
  return r-st+1;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    z=fndnxt(n);
    lst=fndnxt(z*(n-1)+1);
    for (i=0; i<n-1; i++) {
      for (j=0; j<n-1; j++) printf("1 ");
      printf("%d\n",z);
    }
    for (j=0; j<n-1; j++) printf("%d ",z);
    printf("%d\n",lst);
  }
  return 0;
}