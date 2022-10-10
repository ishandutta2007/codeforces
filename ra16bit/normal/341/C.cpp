#include <stdio.h>
const int md=1000000007;
int i,j,n,x,N,M,f[2002][2002];
bool a[2002],b[2002];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d",&x);
	if (x==-1) a[i]=true; else b[x]=true;
  }
  for (i=1; i<=n; i++) if (a[i]) {
    if (!b[i]) N++; else M++;
  }
  f[0][0]=1;
  for (i=0; i<=N; i++) for (j=0; j<=M+1; j++) if (i+j>0) {
    if (j==0) {
	  if (i>1) f[i][j]=((i-1LL)*f[i-2][1])%md;
	} else {
	  if (j>0) f[i][j]=(f[i][j]+((long long)j)*f[i][j-1])%md;
	  if (i>0) f[i][j]=(f[i][j]+((long long)i)*f[i-1][j])%md;
	}
  }
  printf("%d\n",f[N][M]);
  return 0;
}