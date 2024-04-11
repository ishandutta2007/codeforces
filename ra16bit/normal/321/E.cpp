#include <bits/stdc++.h>
using namespace std;
int n,m,it,i,j,a[4040][4040],s[4040][4040],f[808][4040],w[808][4040];
char st[8040];
void solve(int i, int L, int R) {
  int mid=(L+R)/2;
  int rgh=(R==n)?mid-1:w[i][R+1];
  int prv=w[i][mid]=w[i][L-1];
  f[i][mid]=f[i-1][prv]+s[mid][prv];
  for (++prv; prv<mid && prv<=rgh; prv++) {
    int cur=f[i-1][prv]+s[mid][prv];
    if (cur<f[i][mid]) {
      f[i][mid]=cur;
      w[i][mid]=prv;
    }
  }
  if (L<mid) solve(i,L,mid-1);
  if (mid<R) solve(i,mid+1,R);
}
int main() {
  scanf("%d%d",&n,&m);
  gets(st);
  for (i=1; i<=n; i++) {
    gets(st);
    for (j=1; j<=n; j++) {
      a[i][j]=st[j*2-2]-'0';
      //a[i][j]=int(i!=j)*(i%10);
      a[i][j]+=a[i-1][j];
      a[i][j]+=a[i][j-1];
      a[i][j]-=a[i-1][j-1];
    }
  }
  for (i=1; i<=n; i++) f[1][i]=a[i][i];
  for (i=0; i<=n; i++) for (j=i; j<=n; j++) s[j][i]=a[j][j]-a[i][j]-a[j][i]+a[i][i];
  for (i=2; i<=m; i++) {
    f[i][i]=f[i-1][i-1];
    w[i][i]=i-1;
    if (i<n) solve(i,i+1,n);
  }
  printf("%d\n",f[m][n]/2);
  //printf("it=%d\n",it);
  return 0;
}