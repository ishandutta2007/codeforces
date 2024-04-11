#include <bits/stdc++.h>
using namespace std;
int n,i,j,k,r,a[100100],b[100100];
bool u[100100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    b[i]=a[i];
  }
  sort(b,b+n);
  for (i=0; i<n; i++) a[i]=lower_bound(b,b+n,a[i])-b;
  for (i=0; i<n; i++) if (!u[i]) {
    for (j=i; !u[j]; j=a[j]) u[j]=true;
    r++;
  }
  printf("%d\n",r);
  for (i=0; i<n; i++) if (u[i]) {
    for (k=0, j=i; u[j]; j=a[j], k++) {
      b[k]=j;
      u[j]=false;
    }
    sort(b,b+k);
    printf("%d",k);
    for (j=0; j<k; j++) printf(" %d",b[j]+1);
    puts("");
  }
  return 0;
}