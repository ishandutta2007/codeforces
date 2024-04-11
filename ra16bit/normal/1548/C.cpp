#include <bits/stdc++.h>
using namespace std;
const int MX=3000300,md=1000000007;
int n,q,i,mx,r[MX];
long long f[MX],o[MX],o3,cur;
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  scanf("%d%d",&n,&q);
  mx=3*n+3;
  for (f[0]=o[0]=i=1; i<=mx; i++) {
    f[i]=(f[i-1]*i)%md;
    o[i]=pw(f[i],md-2);
  }
  o3=pw(3,md-2);
  r[1]=n+1;
  for (i=4; i<=mx; i+=3) if ((r[2]+=i-1)>=md) r[2]-=md;
  for (i=3; i<=mx; i++) {
    cur=(f[mx]*o[i])%md;
    cur=(cur*o[mx-i])%md;
    if ((cur-=r[i-2])<0) cur+=md;
    cur=(cur*o3)%md;
    if ((cur-=r[i-1])<0) cur+=md;
    r[i]=cur;
  }
  while (q--) {
    scanf("%d",&i);
    printf("%d\n",r[i+1]);
  }
  return 0;
}