#include <bits/stdc++.h>
using namespace std;
int t,n,d,md,i,j,r,f[44];
long long cur;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&d,&md);
    for (n=1; (1<<n)<=d; n++);
    r=0; f[0]=1%md;
    for (i=1; i<=n; i++) {
      cur=((i==n)?d-(1<<(i-1))+1:(1<<(i-1)))%md;
      for (f[i]=j=0; j<i; j++) f[i]=(f[i]+f[j]*cur)%md;
      r=(r+f[i])%md;
    }
    printf("%d\n",r);
  }
  return 0;
}