#include <cstdio>
#include <map>
using namespace std;
int n,i,a,b,cc,c[100100],mask[100100],x[100100];
map<int,int> m;
void dfs(int i) {
  c[i]=cc;
  if (m.count(a-x[i])) {
    int j=m[a-x[i]];
    if (c[j]==0) dfs(j);
  } else if (mask[cc]&1) mask[cc]^=1;
  if (m.count(b-x[i])) {
    int j=m[b-x[i]];
    if (c[j]==0) dfs(j);
  } else if (mask[cc]&2) mask[cc]^=2;
}
int main() {
  scanf("%d%d%d",&n,&a,&b);
  for (i=1; i<=n; i++) {
    scanf("%d",&x[i]);
    m[x[i]]=i;
  }
  for (i=1; i<=n; i++) if (c[i]==0) {
    mask[++cc]=3;
    dfs(i);
    if (mask[cc]==0) { puts("NO"); return 0; }
  }
  puts("YES");
  for (i=1; i<=n; i++) printf("%d%c",1-(mask[c[i]]&1),i==n?'\n':' ');
  return 0;
}