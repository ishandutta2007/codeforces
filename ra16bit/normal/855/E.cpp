#include <bits/stdc++.h>
using namespace std;
const long long MX=999999999999999999LL;
int b,msk,cnt,t,i,j,k,a[62];
long long f[11][62][1025],ii,jj;
long long solve(int b, long long x) {
  if (x<=0) return 0;
  for (cnt=0; x>0; x/=b) a[cnt++]=x%b;
  long long res=0;
  for (int i=1; i<cnt; i++) for (int j=1; j<b; j++) res+=f[b][i-1][(1<<j)];
  int msk=0;
  for (int i=cnt-1; i>=0; i--) {
    for (int j=int(i==cnt-1); j<a[i]; j++) res+=f[b][i][msk^(1<<j)];
    msk^=(1<<a[i]);
  }
  return res+f[b][0][msk];
}
int main() {
  for (b=2; b<=10; b++) {
    msk=(1<<b);
    f[b][0][0]=1;
    for (cnt=0, ii=MX; ii>0; ii/=b) cnt++;
    for (i=1; i<=cnt; i++) for (j=0; j<msk; j++) for (k=0; k<b; k++) f[b][i][j]+=f[b][i-1][j^(1<<k)];
  }
  scanf("%d",&t);
  while (t--) {
    scanf("%d%lld%lld",&b,&ii,&jj);
    printf("%lld\n",solve(b,jj)-solve(b,ii-1));
  }
  return 0;
}