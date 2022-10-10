#include <bits/stdc++.h>
using namespace std;
int m,n,i,j,c;
vector<int> r;
int main() {
  scanf("%d",&m);
  n=(m+1)*5;
  for (i=1; i<=n; i++) {
    for (c=0, j=5; j<=i; j*=5) c+=i/j;
    if (c==m) r.push_back(i);
  }
  printf("%d\n",int(r.size()));
  for (i=0; i<r.size(); i++) printf("%d ",r[i]);
  return 0;
}