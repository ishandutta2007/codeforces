#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,it,x,a[303],w[303];
char s[303][303];
bool u[303];
void dfs(int i) {
  if (!u[a[i]]) x=min(x,a[i]);
  w[i]=it;
  for (int j=0; j<n; j++) if (s[i][j]=='1' && w[j]!=it) dfs(j);
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) scanf("%s",s[i]);
  for (i=0; i<n; i++) {
    ++it; x=n;
    dfs(i);
    u[x]=true;
    printf("%d%c",x,(i==n-1)?'\n':' ');
  }
  return 0;
}