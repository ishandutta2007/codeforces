#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,x,m,t,p[1000100],st[1000100];
bool o[1000100];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&p[i]);
  scanf("%d",&m);
  for (i=0; i<m; i++) { scanf("%d",&x); x--; o[x]=true; }
  reverse(p,p+n);
  reverse(o,o+n);
  for (i=0; i<n; i++) if (t>0 && st[t]==p[i] && !o[i]) t--; else {
    st[++t]=p[i];
	p[i]=-p[i];
  }
  if (t==0) {
    puts("YES");
	reverse(p,p+n);
    for (i=0; i<n; i++) printf("%d%c",p[i],(i==n-1)?'\n':' ');
  } else puts("NO");
  return 0;
}