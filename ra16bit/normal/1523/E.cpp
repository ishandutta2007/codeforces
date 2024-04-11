#include <bits/stdc++.h>
using namespace std;
const int MX=100100,md=1000000007;
int t,n,m,num,i;
long long f[MX],rp,rq;
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void updr(long long p, long long q) {
  rp=(rp*q+p*rq)%md;
  rq=(rq*q)%md;
}
int main() {
  for (f[0]=i=1; i<MX; i++) f[i]=(f[i-1]*i)%md;
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    rp=rq=1;
    for (i=1; ; i++) {
      num=n-(i-1)*(m-1);
      if (num<i) break;
      updr((f[num]*f[n-i])%md,(f[n]*f[num-i])%md);
    }
    printf("%d\n",int((rp*pw(rq,md-2))%md));
  }
  return 0;
}