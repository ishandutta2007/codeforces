#include <bits/stdc++.h>
using namespace std;
int n,a,x,y,i;
set<int> s; 
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a);
    s.insert(-a);
  }
  while (true) {
    x=-*s.begin();
    s.erase(s.begin());
    for (y=x/2; y>0; y/=2) if (!s.count(-y)) {
      s.insert(-y);
      break;
    }
    if (y<=0) {
      s.insert(-x);
      for (auto it=s.begin(); it!=s.end(); it++) printf("%d ",-*it);
      break;
    }
  }
  return 0;
}