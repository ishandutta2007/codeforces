#include <stdio.h>
const int md=1000000007;
int n,m,i,cur,r;
char a[100100];
long long c,s[100100],p10[100100],f[100100],o[100100];
long long pw(int a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (a*pw(a,b-1))%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  scanf("%d%d",&n,&m);
  for (p10[0]=f[0]=o[0]=i=1; i<n; i++) {
    p10[i]=(p10[i-1]*10LL)%md;
    f[i]=(f[i-1]*i)%md;
    o[i]=pw(f[i],md-2);
  }
  for (i=0; i<n; i++) {
    if (m<=n-i-1) c=(((f[n-2-i]*o[m-1])%md)*o[n-i-m-1])%md; else c=0;
    s[i]=(s[i-1]+c*p10[i])%md;
  }
  scanf("%s",a);
  for (i=0; i<n; i++) {
    cur=a[i]-'0';
    r=(r+s[n-2-i]*cur)%md;
    if (m<=i) c=(((f[i]*o[m])%md)*o[i-m])%md; else c=0;
    c=(c*p10[n-i-1])%md;
    r=(r+c*cur)%md;
  }
  printf("%d\n",r);
  return 0;
}