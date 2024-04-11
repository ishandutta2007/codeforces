#include <bits/stdc++.h>
using namespace std;
const int MX=100100;
int t,n,m,i,lst,cur,r,a[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&m,&n);
    for (i=0; i<n; i++) scanf("%d",&a[i]);
    sort(a,a+n);
    lst=m-a[n-1];
    for (i=n-1; i>0; i--) a[i]=a[i]-a[i-1]-1;
    a[0]=a[0]-1+lst;
    sort(a,a+n);
    r=cur=0;
    for (i=n-1; i>=0; i--) if (a[i]>0) {
      if (a[i]-cur>2) {
        r+=cur+1;
        cur+=4;
      } else if (a[i]-cur>0) {
        r+=a[i]-1;
        cur+=2;
      } else r+=a[i];
    }
    printf("%d\n",n+r);
  }
  return 0;
}