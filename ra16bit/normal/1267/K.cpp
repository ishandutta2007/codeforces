#include <bits/stdc++.h>
using namespace std;
int t,n,i,j,w,a[77];
long long c[77][77],x,r,z;
int main() {
  for (i=0; i<77; i++) {
    c[i][0]=1;
    for (j=1; j<=i; j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
  }
  scanf("%d",&t);
  while (t--) {
    scanf("%I64d",&x);
    for (n=0, i=2; x>0; i++) {
      a[++n]=x%i; x/=i;
    }
    sort(a+1,a+n+1);
    r=1; z=int(a[1]==0);
    for (i=0; i<n; i=j) {
      for (j=i; j<n && a[n-i]==a[n-j]; j++);
      if (j<n) {
        w=max(a[n-i],1);
        r*=c[n-i-w+1][j-i];
        if (w<=n-i-1) z*=c[n-i-1-w+1][j-i]; else z=0;
      }
    }
    printf("%I64d\n",r-z-1);
  }
  return 0;
}