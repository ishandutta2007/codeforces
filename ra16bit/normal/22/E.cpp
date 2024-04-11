#include <cstdio>
#include <vector>
using namespace std;
int a[100100],i,j,b[100100],n;
bool c[100100],u[100100],d[100100];
vector <int> p,q;
void dfs(int i) {
  u[i]=true;
  if (!u[a[i]]) dfs(a[i]);
  b[i]=b[a[i]];
  if (b[i]==0) b[i]=i;
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) { scanf("%d",&a[i]); c[a[i]]=true; }
  for (i=1; i<=n; i++) if (!u[i]) dfs(i);
  for (i=1; i<=n; i++) if (!c[i]) { p.push_back(i); q.push_back(b[i]); d[b[i]]=true; }
  for (j=p.size(),i=1; i<=n; i++) if (b[i]==i && !d[i]) { p.push_back(i); q.push_back(b[i]); }
  n=p.size();
  if (n==1 && j==0) n=0;
  printf("%d\n",n);
  for (i=0; i<n; i++) printf("%d %d\n",q[i],p[(i+1)%n]);
  return 0;
}