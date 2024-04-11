#include <cstdio>
#include <vector>
using namespace std;
const int md=1000000007;
int n,m,i,j,k,r,f[2002][2002];
vector<int> a[2002];
int main() {
  scanf("%d%d",&m,&n);
  for (i=1; i<=m; i++) {
    f[1][i]=1;
    for (j=1; j<=i; j++) if (i%j==0) a[i].push_back(j);
  }
  for (i=2; i<=n; i++) for (j=1; j<=m; j++) for (k=0; k<a[j].size(); k++) {
    f[i][j]+=f[i-1][a[j][k]];
    if (f[i][j]>=md) f[i][j]-=md;
  }
  for (i=1; i<=m; i++) {
    r+=f[n][i];
    if (r>=md) r-=md;
  }
  printf("%d\n",r);
  return 0;
}