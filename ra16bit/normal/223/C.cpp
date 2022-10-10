#include <stdio.h>
const int md=1000000007;
int i,j,cur,n,m,a[2020];
long long b[2020];
long long pw(int a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  if (m==0) {
    for (i=0; i<n; i++) printf("%d%c",a[i],(i==n-1)?'\n':' ');
    return 0;
  }
  b[0]=1;
  for (i=1; i<n; i++) {
    b[i]=(b[i-1]*(m-1+i))%md;
	b[i]=(b[i]*pw(i,md-2))%md;
  }
  for (i=0; i<n; i++) {
    for (cur=j=0; j<=i; j++) cur=(cur+b[i-j]*a[j])%md;
    printf("%d%c",cur,(i==n-1)?'\n':' ');
  }
  return 0;
}