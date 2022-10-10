#include <map>
#include <utility>
#include <cstdio>
using namespace std;
int n,i,j,k,v,mx,mz,c,l,r[111111],p[111111],g[111111],res[111111];
pair<int, int> x,z;
map <pair<int, int>,int> m;
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%d%d%d%d",&v,&c,&l,&r[i]);
    z=make_pair(l+c+r[i],l+c);
    if (l==0) {
      mz=m[z]; p[i]=v;
      if (mz==0 || v>p[mz]) m[z]=i;
      continue;
    }
    x=make_pair(l+c+r[i],l); mx=m[x];
    if (mx==0) continue;
    mz=m[z]; p[i]=p[mx]+v; g[i]=mx;
    if (mz==0 || p[i]>p[mz]) m[z]=i;
  }
  j=0; p[j]=0;
  for (i=1; i<=n; i++) if (p[i]>p[j] && r[i]==0) j=i;
  for (; j>0; j=g[j]) res[k++]=j;
  printf("%d\n",k);
  for (i=k-1; i>=0; i--) {
    if (i<k-1) putchar(' ');
    printf("%d",res[i]);
  }
  return 0;
}