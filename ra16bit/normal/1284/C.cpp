#include <bits/stdc++.h>
using namespace std;
int n,md,i,r;
long long f[250250];
long long sqr(long long x) { return (x*x)%md; }
int main() {
  scanf("%d%d",&n,&md);
  for (f[0]=i=1; i<=n; i++) f[i]=(f[i-1]*i)%md;
  for (i=1; i<=n; i++) r=(r+((f[i]*f[n-i])%md)*sqr(n-i+1))%md;
  printf("%d\n",r);
  return 0;
}