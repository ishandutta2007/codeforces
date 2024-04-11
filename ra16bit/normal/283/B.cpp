#include <stdio.h>
int n,i,a[200200];
long long f[200200][2];
bool w[200200][2];
void dfs(int i, int j) {
  w[i][j]=true;
  int x=i+(j==0?a[i]:-a[i]);
  long long r;
  if (x<=0 || x>n || (x==1 && j==0)) r=0; else if (w[x][1-j]) r=-1; else {
    if (f[x][1-j]==0) dfs(x,1-j);
	r=f[x][1-j];
  }
  f[i][j]=r<0?-1:(r+a[i]);
  w[i][j]=false;
}
int main() {
  scanf("%d",&n);
  for (i=2; i<=n; i++) scanf("%d",&a[i]);
  w[1][0]=true;
  for (i=2; i<=n; i++) {
    if (f[i][1]==0) dfs(i,1);
	printf("%I64d\n",f[i][1]<0?-1LL:(i-1LL+f[i][1]));
  }
  return 0;
}