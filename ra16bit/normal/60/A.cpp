#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,i,l,r,x;
char s[55];
bool q;
int main() {
  scanf("%d%d",&n,&m);
  l=1; r=n;
  for (i=0; i<m; i++) {
    scanf("%s",s);
    scanf("%s",s);
    scanf("%s",s);
    q=(s[0]=='l');
    scanf("%s",s);
    scanf("%d",&x);
    if (q) r=min(x-1,r); else l=max(x+1,l);
  }
  if (l>r) puts("-1"); else printf("%d\n",r-l+1);
  return 0;
}