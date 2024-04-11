#include <bits/stdc++.h>
using namespace std;
int x,d,p,i,j;
vector<long long> a;
long long cur=1;
int main() {
  scanf("%d%d",&x,&d);
  for (i=30; i>0; i--) {
    for (p=(1<<i)-1; x>=p; x-=p) {
      for (j=0; j<i; j++) a.push_back(cur);
      cur+=d;
    }
  }
  printf("%d\n",int(a.size()));
  for (i=0; i<a.size(); i++) printf("%lld ",a[i]);
  return 0;
}