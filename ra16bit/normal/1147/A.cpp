#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,x,r,a[100100],fi[100100],lst[100100];
bool ok(int i, int j) {
  if (i==j) return lst[i]==0;
  if (lst[i]==0 || lst[j]==0) return true;
  return lst[j]<fi[i];
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=m; i++) {
    scanf("%d",&a[i]);
    if (fi[a[i]]==0) fi[a[i]]=i;
    lst[a[i]]=i;
  }
  for (i=1; i<=n; i++) for (j=-1; j<=1; j++) {
    x=i+j;
    if (x>=1 && x<=n && ok(i,x)) r++;
  }
  printf("%d\n",r);
  return 0;
}