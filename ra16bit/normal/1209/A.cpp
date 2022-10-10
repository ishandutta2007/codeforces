#include <bits/stdc++.h>
using namespace std;
int n,i,j,r,a[111];
bool u[111];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  sort(a,a+n);
  for (i=0; i<n; i++) if (!u[i]) {
    for (j=i; j<n; j++) if (!u[j] && a[j]%a[i]==0) u[j]=true;
    r++;
  }
  printf("%d\n",r);
  return 0;
}