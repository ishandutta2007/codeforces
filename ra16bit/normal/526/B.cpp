#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,r,a[4444];
int dfs(int i) {
  if (i*2>=m) return a[i];
  int x=dfs(i*2);
  int y=dfs(i*2+1);
  if (x<y) swap(x,y);
  r+=x-y;
  return x+a[i];
}
int main() {
  scanf("%d",&n);
  m=(1<<(n+1));
  for (i=2; i<m; i++) scanf("%d",&a[i]);
  dfs(1);
  printf("%d\n",r);
  return 0;
}