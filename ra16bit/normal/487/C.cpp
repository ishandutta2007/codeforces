#include <stdio.h>
int n,m,i,j,p,phi,a[100100],b[100100];
long long x;
long long pw(int a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%n;
  long long x=pw(a,b/2);
  return (x*x)%n;
}
int main() {
  scanf("%d",&n);
  if (n==1) {
    puts("YES\n1");
    return 0;
  }
  if (n==4) {
    puts("YES\n1\n3\n2\n4");
    return 0;
  }
  for (i=2; i*i<=n; i++) if (n%i==0) {
    puts("NO");
    return 0;
  }
  p=phi=n-1;
  for (i=2; i*i<=p; i++) if (p%i==0) {
    a[m++]=i;
    while (p%i==0) p/=i;
  }
  if (p>1) a[m++]=p;
  for (i=2; i<=n; i++) {
    for (j=0; j<m; j++) if (pw(i,phi/a[j])==1) break;
    if (j>=m) break;
  }
  for (x=1, j=0; j<n; j++, x=(x*i)%n) b[j]=x;
  puts("YES\n1");
  for (j=1; j<n-1; j++) printf("%d\n",b[(j&1)?j:(n-j-1)]);
  printf("%d\n",n);
  return 0;
}