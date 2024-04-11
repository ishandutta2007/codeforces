#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,x[55];
set<int> s;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    s.clear();
    for (i=0; i<n; i++) {
      scanf("%d",&x[i]);
      for (j=0; j<i; j++) s.insert(x[i]-x[j]);
    }
    printf("%d\n",int(s.size()));
  }
  return 0;
}