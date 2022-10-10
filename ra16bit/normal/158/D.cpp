#include <stdio.h>
int n,i,j,r,a[20200],b[20200];
void solve(int k) {
  for (j=0; j<k; j++) b[j]=0;
  for (j=0; j<n; j++) b[j%k]+=a[j];
  for (j=0; j<k; j++) if (b[j]>r) r=b[j];
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&a[i]); r+=a[i]; }
  for (i=2; i*i<=n; i++) if (n%i==0) {
    if (i>=3) solve(n/i);
    if (n/i>=3 && i*i!=n) solve(i);
  }
  printf("%d\n",r);
  return 0;
}