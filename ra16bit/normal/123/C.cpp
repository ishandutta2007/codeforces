#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,j,cur,ii,a[102][102],b[222],c[222];
long long f[222][222],k,cz;
char d[222],r[102][102];
bool cmp(int i, int j) { return b[i]<b[j]; }
inline long long go(int n) {
  f[0][0]=1;
  for (i=1; i<=n; i++) for (j=0; j<=i; j++) {
    f[i][j]=0;
    if (j>0 && d[i-1]!=')') f[i][j]+=f[i-1][j-1];
    if (d[i-1]!='(') f[i][j]+=f[i-1][j+1];
    if (f[i][j]>k+5) f[i][j]=k+5;
  }
  return f[n][0];
}
int main() {
  scanf("%d%d%I64d",&n,&m,&k);
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    scanf("%d",&a[i][j]);
    if (b[i+j]==0 || a[i][j]<b[i+j]) b[i+j]=a[i][j];
  }
  for (i=0; i<n+m-1; i++) c[i]=i;
  sort(c,c+n+m-1,cmp);
  for (ii=0; ii<n+m-1; ii++) {
    cur=c[ii];
    d[cur]='(';
    cz=go(n+m-1);
    if (k>cz) {
      d[cur]=')';
      k-=cz;
    }
  }
  for (i=0; i<n; i++) for (j=0; j<m; j++) r[i][j]=d[i+j];
  for (i=0; i<n; i++) puts(r[i]);
  return 0;
}