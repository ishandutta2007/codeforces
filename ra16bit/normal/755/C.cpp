#include <cstdio>
using namespace std;
int n,r,i,x,p[10100];
int fs(int x) {
  if (x!=p[x]) p[x]=fs(p[x]);
  return p[x];
}
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) p[i]=i;
  for (i=1; i<=n; i++) {
    scanf("%d",&x);
    if (fs(x)!=fs(i)) p[i]=x;
  }
  for (i=1; i<=n; i++) if (fs(i)==i) r++;
  printf("%d\n",r);
  return 0;
}