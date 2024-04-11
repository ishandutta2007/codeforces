#include <bits/stdc++.h>
using namespace std;
int t,l,r,b;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&l,&r);
    b=max(l,r/2+1);
    printf("%d\n",r%b);
  }
  return 0;
}