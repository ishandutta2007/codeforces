#include <bits/stdc++.h>
using namespace std;
int t,n,i,x,r;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (r=i=0; i<n; i++) {
      scanf("%d",&x);
      r+=x-1;
    }
    puts((r&1)?"errorgorn":"maomao90");
  }
  return 0;
}