#include <bits/stdc++.h>
using namespace std;
int a,b,c,n,i,x,r;
int main() {
  scanf("%d%d%d%d",&a,&b,&c,&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    if (x>b && x<c) r++;
  }
  printf("%d\n",r);
  return 0;
}