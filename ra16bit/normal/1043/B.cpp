#include <bits/stdc++.h>
using namespace std;
int n,i,j,a[1010];
vector<int> r;
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=n; i>0; i--) a[i]-=a[i-1];
  for (i=1; i<=n; i++) {
    for (j=i+1; j<=n; j++) if (a[j]!=a[j-i]) break;
    if (j>n) r.push_back(i);
  }
  printf("%d\n",int(r.size()));
  for (i=0; i<r.size(); i++) printf("%d ",r[i]);
  return 0;
}