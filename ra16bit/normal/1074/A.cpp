#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,e,r,l,y,a[100100],x[100100];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  a[n]=r=1000000000;
  for (i=0; i<m; i++) {
    scanf("%d%d%d",&l,&x[e],&y);
	if (l==1) e++;
  }
  sort(a,a+n);
  sort(x,x+e);
  for (i=j=0; i<=n; i++) {
    for (; j<e && x[j]<a[i]; j++);
	r=min(r,e-j+i);
  }
  printf("%d\n",r);
  return 0;
}