#include <bits/stdc++.h>
using namespace std;
const int md=998244353;
int n,m,l,r,x,y,i,j,k,ii,res;
long long s,f[4][4],a[4][4],c[4][4];
long long pw(long long a, long long b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
int main() {
  scanf("%d%d%d%d",&n,&m,&l,&r);
  if (l==r) {
    puts("1");
    return 0;
  }
  x=r-l+1;
  y=x/2;
  s=n; s*=m;
  a[0][1]=y; a[0][2]=x-y;
  a[1][0]=y; a[1][3]=x-y;
  a[2][3]=y; a[2][0]=x-y;
  a[3][2]=y; a[3][1]=x-y;
  for (i=0; i<4; i++) f[i][i]=1;
  for (ii=60; ii>=0; ii--) {
  for (i=0; i<4; i++) for (j=0; j<4; j++) for (c[i][j]=k=0; k<4; k++)
    c[i][j]=(c[i][j]+f[i][k]*f[k][j])%md;
    if ((s>>ii)&1) {
      for (i=0; i<4; i++) for (j=0; j<4; j++) for (f[i][j]=k=0; k<4; k++)
        f[i][j]=(f[i][j]+c[i][k]*a[k][j])%md;
    } else for (i=0; i<4; i++) for (j=0; j<4; j++) f[i][j]=c[i][j];
  }
  if (s%2==0) printf("%d\n",int(f[0][0])); else printf("%d\n",int((f[0][1]+f[0][2])%md));
  return 0;
}