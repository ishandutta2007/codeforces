#include <bits/stdc++.h>
using namespace std;
const int MX=102;
int n,m,k,md,f[MX][MX][MX];
long long c[MX][MX],fact[MX];
bool u[MX][MX][MX];
long long solve(int i, int j, int k) {
  if (j==m-1) return (k==1)?fact[i]:0;
  if (i==1) return int(k==0);
  if (k>i) return 0;
  if (u[i][j][k]) return f[i][j][k];
  u[i][j][k]=true;
  f[i][j][k]=(2*solve(i-1,j+1,k))%md;
  for (int pos=2; pos<i; pos++) {
    long long cur=0;
    int cle=0;
    for (; cle*2<k && cle<pos; cle++) cur=(cur+solve(pos-1,j+1,cle)*solve(i-pos,j+1,k-cle))%md;
    cur=(cur*2)%md;
    if (cle*2==k) cur=(cur+solve(pos-1,j+1,cle)*solve(i-pos,j+1,k-cle))%md;
    f[i][j][k]=(f[i][j][k]+cur*c[i-1][pos-1])%md;
  }
  return f[i][j][k];
}
int main() {
  scanf("%d%d%d%d",&n,&m,&k,&md);
  if (md==1 || m+k>n+1) { puts("0"); return 0; }
  for (int i=0; i<=n; i++) {
    fact[i]=i?(fact[i-1]*i)%md:1LL;
    c[i][0]=1;
    for (int j=1; j<=n; j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;
  }
  printf("%d\n",solve(n,0,k));
  return 0;
}