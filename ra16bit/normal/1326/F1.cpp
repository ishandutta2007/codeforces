#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,a[22],b[1<<18];
long long f[1<<18][18],g[1<<18];
char s[22][22];
void rec(int sum, int x, int mask) {
  if (sum==0) {
    for (i=0; i<(1<<n); i++) for (j=0; j<n; j++) f[i][j]=0;
    for (i=0; i<n; i++) f[1<<i][i]=1;
    for (i=0; i<(1<<n)-1; i++) for (j=0; j<n; j++) if (f[i][j]) {
      for (k=0; k<n; k++) if (((i>>k)&1)==0 && (s[j][k]=='1' || ((mask>>(b[i]-1))&1)==0)) f[i^(1<<k)][k]+=f[i][j];
    }
    for (j=0; j<n; j++) g[mask]+=f[i][j];
    return;
  }
  for (; x>0; x--) rec(sum-x,min(sum-x,x),(mask<<x)+(1<<(x-1))-1);
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=0; i<(1<<n); i++) b[i]=b[i/2]+(i&1);
  rec(n,n,0);
  for (i=0; i<(1<<(n-1)); i++) {
    for (m=0, j=-1; j<n-1; j=k) {
      for (k=j+1; k<n-1 && ((i>>k)&1); k++);
      a[m++]=k-j;
    }
    sort(a,a+m);
    reverse(a,a+m);
    for (k=j=0; j<m; j++) k=(k<<a[j])+(1<<(a[j]-1))-1;
    g[i]=g[k];
  }
  for (i=(1<<(n-1))-1; i>0; i--) for (j=(i&(i-1)); ; j=((j-1)&i)) {
    g[j]-=g[i];
    if (j==0) break;
  }
  for (i=0; i<(1<<(n-1)); i++) printf("%I64d ",g[i]);
  return 0;
}