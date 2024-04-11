#include <bits/stdc++.h>
using namespace std;
int t,n,m,i,s,x;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    for (s=i=0; i<n; i++) {
      scanf("%d",&x);
      s+=x;
    }
    puts((s==m)?"YES":"NO");
  }
  return 0;
}