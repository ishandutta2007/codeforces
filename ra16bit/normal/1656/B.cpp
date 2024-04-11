#include <bits/stdc++.h>
using namespace std;
int t,n,m,x,i;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    set<int> s;
    bool was=false;
    for (i=0; i<n; i++) {
      scanf("%d",&x);
      if (!was) {
        if (s.count(x-m) || s.count(x+m)) was=true; else s.insert(x);
      }
    }
    puts(was?"YES":"NO");
  }
  return 0;
}