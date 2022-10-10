#include <stdio.h>
const int md=1000000007;
int n,m,i,cur,cnt,a[1000100],b[1000100],r=1;
long long j;
bool u[1000100];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  scanf("%d%d",&n,&m);
  if (m==0) {
    printf("%d\n",int(pw(n,n-1)));
    return 0;
  }
  for (i=0; i<n; i++) if (!u[i]) {
    for (j=i, cnt=0; !u[j]; j=(m*j)%n, cnt++) u[j]=true;
    a[cnt]++;
  }
  for (i=1; i<=n; i++) if (a[i]) {
    cur=a[i]*i;
    for (j=i; j<=n; j+=i) b[j]+=cur;
    r=(r*pw(b[i],a[i]))%md;
  }
  printf("%d\n",r);
  return 0;
}