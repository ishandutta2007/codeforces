#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,n,i,j,x,r;
long long a[MX],b[18][MX],g,ng;
long long gcd(long long a, long long b) {
  return b?gcd(b,a%b):a;
}
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (i=0; i<n; i++) scanf("%lld",&a[i]);
    if (n==1) { printf("%d\n",n); continue; }
    for (i=1; i<n; i++) b[0][i]=max(a[i],a[i-1])-min(a[i],a[i-1]);
    for (j=1; j<18; j++) for (i=1; i<n; i++) {
      x=i+(1<<(j-1));
      b[j][i]=(x>=n)?1:gcd(b[j-1][i],b[j-1][x]);
    }
    for (r=i=1; i<n; i++) {
      x=i;
      for (j=17; j>=0; j--) if (x<n) {
        ng=((x==i)?b[j][x]:gcd(g,b[j][x]));
        if (ng>1) { g=ng; x+=(1<<j); }
      }
      r=max(r,x-i+1);
    }
    printf("%d\n",r);
  }
  return 0;
}