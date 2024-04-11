#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int n,x,y,z,k,i,s[222222];
vector <int> g[222222];
map <int, int> m;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x); y=m[x];
    if (y==0) { m[x]=y=++k; s[k]=x; }
    scanf("%d",&x); z=m[x];
    if (z==0) { m[x]=z=++k; s[k]=x; }
    g[y].push_back(z);
    g[z].push_back(y);
  }
  for (i=1; i<=k; i++) if (g[i].size()==1) {
    y=i; printf("%d",s[i]);
    for (x=g[i][0]; g[x].size()==2; y=z) {
      printf(" %d",s[x]); z=x;
      if (g[x][0]==y) x=g[x][1]; else x=g[x][0];
    }
    printf(" %d\n",s[x]); break;
  }
  return 0;
}