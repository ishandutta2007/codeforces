#include <cstdio>
using namespace std;
int n,m,i,j,k,d[55],e[55];
bool u[55],g[55][55],q;
void dfs(int i) {
  u[i]=true;
  for (int j=1; j<=n; j++) if (g[i][j] && !u[j]) dfs(j);
}
int main() {
  scanf("%d%d",&n,&m); q=true;
  for (i=0; i<m; i++) {
    scanf("%d%d",&j,&k);
    if (j==k && n>1) q=false;
    g[j][k]=g[k][j]=true;
    d[j]++; d[k]++;
  }
  if (m>n || !q) { puts("NO"); return 0; }
  for (j=0, i=1; i<=n; i++) if (d[i]>2) { puts("NO"); return 0; } else if (d[i]==2) j++;
  if (n==1) {
	  puts("YES");
	  if (m==0) puts("1\n1 1"); else puts("0");
	  return 0;
  }
  if (j==n) dfs(1);
  for (k=0, i=1; i<=n; i++) if (d[i]<2 && !u[i]) dfs(i);
  for (i=1; i<=n; i++) if (!u[i]) { puts("NO"); return 0; }
  puts("YES");
  printf("%d\n",n-m);
  for (i=1; i<=n; i++) if (d[i]<2) {
    for (j=1; j<=n; j++) u[j]=false;
    dfs(i);
    for (j=i+1; j<=n; j++) if (d[i]<2 && d[j]<2 && !u[j]) {
      printf("%d %d\n",i,j);
      d[i]++; d[j]++; k++;
	  g[i][j]=g[j][i]=true;
     dfs(i);
    }
  }
  for (i=1; i<=n; i++) if (d[i]<2) for (j=i+1; j<=n; j++) if (d[j]<2) {
      printf("%d %d\n",i,j);
      d[i]++; d[j]++; k++;
	  g[i][j]=g[j][i]=true;
  }
  if (k!=n-m) for (;;);
  return 0;
}