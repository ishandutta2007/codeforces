#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,k,p,c[55],K[55],g[55][55][105],ra[55],rj,rp;
long long A,B,q,a[55],b[55],f[55][55][105],rb[55],r;
bool cmp(int i, int j) { return c[i]<c[j]; }
void go(long long q, int x) {
  for (int e=0; c[K[e]]<c[K[j]]; e++) if (a[K[e]]<=q && b[K[e]]>=q) {
    long long prev=f[i-1][e][q-a[K[e]]];
    if (prev>0 && f[i][j][p]<prev+A+p) {
      f[i][j][p]=prev+A+p;
      g[i][j][p]=(e<<1)+x;
    }
  }
}
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=0; i<m; i++) {
    scanf("%I64d%I64d%d",&a[i],&b[i],&c[i]);
    K[i]=i;
  }
  sort(K,K+m,cmp);
  for (i=0; i<m; i++) {
    A=a[K[i]]; B=b[K[i]];
    for (j=0; j<=B-A; j++) {
      f[1][i][j]=A+j;
      if (n==1 && A+j>r) {
        r=A+j; rj=i; rp=j;
      }
    }
  }
  for (i=2; i<=n; i++) for (j=0; j<m; j++) {
    A=a[K[j]]; B=b[K[j]];
    for (p=0; p<=B-A; p++) {
      q=A+p;
      if (q>k) go(q-k,0);
      if (q%k==0) go(q/k,1);
      if (i==n && f[i][j][p]>r) {
        r=f[i][j][p];
        rj=j; rp=p;
      }
    }
  }
  if (r) {
    puts("YES");
    for (i=n, j=rj, q=a[K[rj]]+rp; i>0; i--) {
      ra[i]=K[j]+1;
      rb[i]=q;
      p=q-a[K[j]];
      if (g[i][j][p]&1) q/=k; else q-=k;
      j=(g[i][j][p]>>1);
    }
    for (i=1; i<=n; i++) printf("%d %I64d\n",ra[i],rb[i]);
  } else puts("NO");
  return 0;
}