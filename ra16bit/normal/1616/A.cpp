#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,r,a[111];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) {
      scanf("%d",&a[i]);
      if (a[i]<0) a[i]=-a[i];
    }
    sort(a,a+n);
    r=int(a[0]==0);
    for (i=0; i<n && a[i]==0; i++);
    for (; i<n; i=j) {
      for (j=i; j<n && a[i]==a[j]; j++);
      if (j>i+1) r+=2; else r+=1;
    }
    printf("%d\n",r);
  }
  return 0;
}