#include <bits/stdc++.h>
using namespace std;
int t,n,r;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (r=0; n>0; n/=10) r=max(r,n%10);
    printf("%d\n",r);
  }
  return 0;
}