#include <bits/stdc++.h>
using namespace std;
const int MX=1100100;
int t,n,s,x,i,m;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (s=i=0; i<n; i++) {
      scanf("%d",&x);
      s+=x;
    }
    puts((s==0)?"NO":"YES");
  }
  return 0;
}